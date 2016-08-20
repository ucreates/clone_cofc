//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "UnitLifeGaugeBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "UIProperty.h"
// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"
// notify
#include "Notifier.h"
using namespace cocos2d;
UnitLifeGaugeBehaviour::UnitLifeGaugeBehaviour(BaseBehaviour* owner) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/ui/lifeGuage/unit", id));
    this->property = new UIProperty("unitLifeGuage", id);
    this->stateMachine = new FiniteStateMachine<UnitLifeGaugeBehaviour>(this);
    this->stateMachine->add("move", new UnitLifeGaugeMoveState());
    this->stateMachine->add("show", new UnitLifeGaugeShowState());
    this->unit = owner;
    Notifier::getInstance()->add(this, this->property);
}
UnitLifeGaugeBehaviour::~UnitLifeGaugeBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void UnitLifeGaugeBehaviour::onCreate(Layer* layer, Position position) {
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position);
    anime->hide();
    anime->addLayer(layer, position.zorder);
    this->stateMachine->play();
}
void UnitLifeGaugeBehaviour::onUpdate(float delta) { this->stateMachine->update(delta); }
void UnitLifeGaugeBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Behaviour_Unit_Life_Show) {
        this->stateMachine->change("show");
    }
    this->stateMachine->play();
}
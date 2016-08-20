//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BeaconEffectBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "EffectProperty.h"
// asset
#include "AnimatorAsset.h"
// notify
#include "Notifier.h"
using namespace cocos2d;
BeaconEffectBehaviour::BeaconEffectBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/effect/beacon", id));
    this->property = new EffectProperty("beacon", id);
    this->stateMachine = new FiniteStateMachine<BeaconEffectBehaviour>(this);
    this->stateMachine->add("show", new BeaconEffectShowState());
    Notifier::getInstance()->add(this, this->property);
}
BeaconEffectBehaviour::~BeaconEffectBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void BeaconEffectBehaviour::onCreate(Layer* layer, Position position) {
    // asset
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position);
    anime->transform(Size(0.75f, 0.75f));
    anime->hide();
    anime->addLayer(layer, position.zorder);
    this->stateMachine->play();
}
void BeaconEffectBehaviour::onUpdate(float delta) { this->stateMachine->update(delta); }
void BeaconEffectBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Behaviour_Unit_Beacon_Show) {
        this->stateMachine->change("show", parameter);
        this->stateMachine->play();
    }
}
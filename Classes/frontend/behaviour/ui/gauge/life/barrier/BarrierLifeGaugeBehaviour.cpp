//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BarrierLifeGaugeBehaviour.h"
#include "BehaviourIdGenerator.h"

// peroperty
#include "UIProperty.h"

// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"

// notify
#include "Notifier.h"

using namespace cocos2d;

BarrierLifeGaugeBehaviour::BarrierLifeGaugeBehaviour(BaseBehaviour* owner) {
    int id = BehaviourIdGenerator::getInstance()->getId();

    this->asset->add("anime", new AnimatorAsset("csb/animation/ui/lifeGuage/barrier", id));
    this->property = new UIProperty("unitLifeGuage", id);
    this->stateMachine = new FiniteStateMachine<BarrierLifeGaugeBehaviour>(this);
    this->stateMachine->add("move", new BarrierLifeGaugeMoveState());
    this->stateMachine->add("show", new BarrierLifeGaugeShowState());
    this->stateMachine->stop();
    this->unit = owner;

    Notifier::getInstance()->add(this, this->property);
}

BarrierLifeGaugeBehaviour::~BarrierLifeGaugeBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }

void BarrierLifeGaugeBehaviour::onCreate(Layer* layer, int depth) {
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(0.0f, 0.0f, depth);
    anime->hide();
    anime->addLayer(layer, depth);

    this->stateMachine->play();
}

void BarrierLifeGaugeBehaviour::onUpdate(float delta) { this->stateMachine->update(delta); }

void BarrierLifeGaugeBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Behaviour_Barrier_Life_Show) {
        this->stateMachine->change("show");
    }
    this->stateMachine->play();
}
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "WallBreakerBehaviour.h"
#include "BehaviourIdGenerator.h"
#include "UnitBehaviourType.h"

// peroperty
#include "UnitProperty.h"

// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"
#include "SoundAssetCollection.h"

// notify
#include "Notifier.h"

#include "Parameter.h"
#include "ServiceGateway.h"

using namespace cocos2d;

WallBreakerBehaviour::WallBreakerBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();

    this->asset->add("anime", new AnimatorAsset("csb/animation/unit/wall_breaker", id));
    this->asset->add("se1", SoundAssetCollection::getInstance()->getSEAsset("sound/se/wall_breaker_attack_01.mp3"));
    this->asset->add("se2", SoundAssetCollection::getInstance()->getSEAsset("sound/se/wall_place_01.mp3"));
    this->property = new UnitProperty("wallbreaker", id);
    this->stateMachine = new FiniteStateMachine<WallBreakerBehaviour>(this);
    this->stateMachine->add("move", new WallBreakerMoveState());
    this->stateMachine->add("attack", new WallBreakerAttackState());
    this->stateMachine->add("win", new WallBreakerWinState());
    this->stateMachine->add("lose", new WallBreakerLoseState());
    this->stateMachine->add("dead", new WallBreakerDeadState());
    this->stateMachine->stop();

    Notifier::getInstance()->add(this, this->property);

    Parameter parameter;
    parameter.set<int>("unitId", id);
    parameter.set<int>("unitType", UnitBehaviourType::WallBreaker);
    Response res = ServiceGateway::getInstance()->request("service://unit/create")->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    res.clear();
}

WallBreakerBehaviour::~WallBreakerBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }

void WallBreakerBehaviour::onCreate(Layer* layer, Position position) {

    BaseUnitBehaviour::onCreate(layer, position);

    this->shadow->onCreate(layer, position, Size(1.0f, 1.0f));

    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position);
    anime->transform(Size(0.75f, 0.75f));
    anime->addLayer(layer, position.zorder);

    // state
    this->stateMachine->change("move");
    this->stateMachine->play();
}

void WallBreakerBehaviour::onUpdate(float delta) {
    BaseUnitBehaviour::onUpdate(delta);
    this->stateMachine->update(delta);
}

void WallBreakerBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Behaviour_Unit_Move) {
        this->stateMachine->change("move");
    } else if (notifyMessage == NotifyMessage::Behaviour_Unit_Attack) {
        this->stateMachine->change("attack", parameter);
    } else if (notifyMessage == NotifyMessage::Behaviour_Unit_Dead) {
        this->stateMachine->change("dead");
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Win_State) {
        this->stateMachine->change("win");
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Lose_State) {
        this->stateMachine->change("lose");
    }
    this->stateMachine->play();
}

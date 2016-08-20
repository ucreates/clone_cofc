//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "GoblinBehaviour.h"
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
#include "Random.h"
#include "Parameter.h"
#include "ServiceGateway.h"
using namespace cocos2d;
GoblinBehaviour::GoblinBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/unit/goblin", id));
    this->asset->add("se1", SoundAssetCollection::getInstance()->getSEAsset("sound/se/goblin_deploy_14v2.mp3"));
    this->asset->add("se2", SoundAssetCollection::getInstance()->getSEAsset("sound/se/goblin_deploy_14v3.mp3"));
    this->asset->add("se3", SoundAssetCollection::getInstance()->getSEAsset("sound/se/gob_attack_01.mp3"));
    this->asset->add("se4", SoundAssetCollection::getInstance()->getSEAsset("sound/se/gob_attack_02.mp3"));
    this->asset->add("se5", SoundAssetCollection::getInstance()->getSEAsset("sound/se/gob_attack_03.mp3"));
    this->property = new UnitProperty("goblin", id);
    this->stateMachine = new FiniteStateMachine<GoblinBehaviour>(this);
    this->stateMachine->add("move", new GoblinMoveState());
    this->stateMachine->add("attack", new GoblinAttackState());
    this->stateMachine->add("win", new GoblinWinState());
    this->stateMachine->add("lose", new GoblinLoseState());
    this->stateMachine->add("dead", new GoblinDeadState());
    this->stateMachine->stop();
    Notifier::getInstance()->add(this, this->property);
    Parameter parameter;
    parameter.set<int>("unitId", id);
    parameter.set<int>("unitType", UnitBehaviourType::Goblin);
    Response res = ServiceGateway::getInstance()->request("service://unit/create")->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    res.clear();
    return;
}
GoblinBehaviour::~GoblinBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void GoblinBehaviour::onCreate(Layer* layer, Position position) {
    BaseUnitBehaviour::onCreate(layer, position);
    this->shadow->onCreate(layer, position, Size(0.8f, 0.8f));
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position);
    anime->transform(Size(0.75f, 0.75f));
    anime->addLayer(layer, position.zorder);
    this->stateMachine->change("move");
    this->stateMachine->play();
    int threshold = Random::create(10);
    std::string seName = "se1";
    if (0 == threshold % 2) {
        seName = "se2";
    }
    SoundEffectAsset* se = (SoundEffectAsset*)this->getAsset(seName.c_str());
    se->play();
}
void GoblinBehaviour::onUpdate(float delta) {
    BaseUnitBehaviour::onUpdate(delta);
    this->stateMachine->update(delta);
}
void GoblinBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
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
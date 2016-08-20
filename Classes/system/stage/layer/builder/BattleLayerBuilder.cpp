//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// behaviour
#include "BehaviourCollection.h"
#include "CloudEffectBehaviour.h"
#include "UnitBehaviourFactory.h"
// command
#include "BaseCommand.h"
#include "CommandGateway.h"
// layer
#include "BattleLayerBuilder.h"
#include "BattleLayer.h"
// geography
#include "GeographicGateway.h"
#include "GeographicDepth.h"
// notifier
#include "Notifier.h"
// service
#include "ServiceGateway.h"
#include "Parameter.h"
// stream
#include "GeographicDataStream.h"
using namespace cocos2d;
BattleLayerBuilder::BattleLayerBuilder() {}
BattleLayerBuilder::~BattleLayerBuilder() {}
BattleLayerBuilder* BattleLayerBuilder::setUnitLayer(Layer* unitLayer) {
    this->unitLayer = unitLayer;
    return this;
}
BattleLayerBuilder* BattleLayerBuilder::setMap(std::string mapDataFileName) {
    this->mapDataFileName = "map/" + mapDataFileName;
    return this;
}
void BattleLayerBuilder::build() {
    BaseLayerBuilder::build();
    this->unitLayer->setScale(this->fov);
    this->rootLayer->addChild(unitLayer, 0, BaseLayer::NODE_LAYER_TAG);
    BattleLayer* battleLayer = (BattleLayer*)this->rootLayer;
    battleLayer->stateMachine = new FiniteStateMachine<BattleLayer>(battleLayer);
    battleLayer->stateMachine->add("zoom", new BattleZoomState());
    battleLayer->stateMachine->add("frame", new BattleFrameState());
    battleLayer->stateMachine->add("shake", new BattleShakeState());
    battleLayer->stateMachine->add("default", new BattleDefaultState());
    battleLayer->stateMachine->add("transition", new BattleTransitionState());
    battleLayer->stateMachine->add("bgm", new BattleBGMState());
    battleLayer->stateMachine->stop();
    Response res = ServiceGateway::getInstance()->request("service://master/create")->update();
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    res.clear();
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    collection->add(new CloudEffectBehaviour());
    GeographicDataStream stream;
    std::map<int, GeographicDataBaseTag*> mapDataFormatMap = stream.read(this->mapDataFileName);
    GeographicGateway::getInstance(&mapDataFormatMap);
    std::string behaviourTypeList[6] = {"unit", "ornament", "weapon", "effect", "ui", "background"};
    for (int i = 0; i < 6; i++) {
        std::string behaviourType = behaviourTypeList[i];
        std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector(behaviourType);
        for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
            BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
            std::string behaviourName = behaviour->getProperty()->getName();
            BaseCommand* command = CommandGateway::getInstance()->getCommand(behaviourType);
            if ("ornament" == behaviourType) {
                command->initialize(behaviour, this->unitLayer);
            } else if ("ui" == behaviourType) {
                command->initialize(behaviour, this->uiLayer);
            } else if ("background" == behaviourType) {
                command->initialize(behaviour, this->unitLayer);
            } else if ("effect" == behaviourType) {
                command->initialize(behaviour, this->uiLayer);
            }
        }
    }
    int barrierCount = collection->getBarrierCount();
    Parameter parameter;
    parameter.set<int>("barrierCount", barrierCount);
    res = ServiceGateway::getInstance()->request("service://battle/preparation")->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    std::map<std::string, int> unitResourceMap = res.get<std::map<std::string, int>>("unitResourceMap");
    for (std::map<std::string, int>::iterator it = unitResourceMap.begin(); it != unitResourceMap.end(); it++) {
        for (int i = 0; i < it->second; i++) {
            BaseBehaviour* behaviour = UnitBehaviourFactory::factoryMethod(it->first);
            collection->addUnitCache(behaviour);
        }
    }
    res.clear();
    Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_Build_State);
    Notifier::getInstance()->add(battleLayer, battleLayer->property);
    battleLayer->stateMachine->play();
    battleLayer->scheduleUpdate();
}
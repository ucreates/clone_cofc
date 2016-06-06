//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// cocos2d
#include "cocos2d.h"

// behaviour
#include "BehaviourMapper.h"
#include "BehaviourCollection.h"

// command
#include "CommandGateway.h"
#include "BaseCommand.h"

// debug
#include "Macro.h"

// state
#include "BattleFrameState.h"

// touch
#include "BaseTouch.h"

using namespace cocos2d;

BattleFrameState::BattleFrameState() { this->persistence = true; }

BattleFrameState::~BattleFrameState() {}

void BattleFrameState::create() {}

void BattleFrameState::update(float delta) {
    Layer* unitLayer = (Layer*)this->owner->getChildByTag(BaseLayer::NODE_LAYER_TAG);
    BehaviourMapper* mapper = BehaviourMapper::getInstance();
    mapper->map(unitLayer);

    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::vector<std::string> behaviourTypeVector = collection->getBehaviourTypeVector();
    for (std::vector<std::string>::iterator it = behaviourTypeVector.begin(); it != behaviourTypeVector.end(); it++) {
        std::string behaviourType = (*it);
        std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector(behaviourType);
        for (std::vector<BaseBehaviour*>::iterator bt = behaviourVector->begin(); bt != behaviourVector->end();) {
            BaseBehaviour* behaviour = (BaseBehaviour*)(*bt);
            std::string behaviourType = behaviour->getProperty()->getType();
            if (BehaviourStatus::COMPLETE == behaviour->getProperty()->getStatus()) {
                if ("weapon" != behaviourType) {
                    delete behaviour;
                    behaviour = NULL;
                }

                bt = behaviourVector->erase(bt);
                continue;
            }
            BaseCommand* command = CommandGateway::getInstance()->getCommand(behaviourType);
            command->execute(behaviour, delta);
            bt++;
        }
    }

    std::map<std::string, BaseTouch*>::iterator it = this->owner->touchMap.begin();
    while (it != this->owner->touchMap.end()) {
        BaseTouch* touch = (BaseTouch*)it->second;
        if (false != touch->getEnableTouch()) {
            touch->onExecute();
        }
        it++;
    }
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BehaviourMapper.h"
#include "BehaviourCollection.h"
#include "Distance.h"

// notify
#include "Notifier.h"

// command
#include "CommandGateway.h"
#include "BaseCommand.h"

using namespace cocos2d;

BehaviourMapper* BehaviourMapper::instance = NULL;

BehaviourMapper::BehaviourMapper() {}

BehaviourMapper* BehaviourMapper::getInstance() {
    if (NULL == BehaviourMapper::instance) {
        BehaviourMapper::instance = new BehaviourMapper();
    }
    return BehaviourMapper::instance;
}

void BehaviourMapper::map(Layer* layer) {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::map<BaseBehaviour*, Position>::iterator it = this->mappingBehaviourMap.begin();
    while (it != this->mappingBehaviourMap.end()) {
        BaseBehaviour* behaviour = (*it).first;
        if (NULL == behaviour) {
            it = this->mappingBehaviourMap.erase(it);
            continue;
        }
        Position position = (*it).second;
        std::string behaviourType = behaviour->getProperty()->getType();
        BaseCommand* command = CommandGateway::getInstance()->getCommand(behaviourType);
        command->initialize(behaviour, layer, position);
        collection->add(behaviour);
        it++;
    }
    this->mappingBehaviourMap.clear();
}

void BehaviourMapper::addMappingList(BaseBehaviour* behaviour, Position position) { this->mappingBehaviourMap.insert(std::map<BaseBehaviour*, Position>::value_type(behaviour, position)); }

void BehaviourMapper::addMappingList(BaseBehaviour* behaviour, Vec2 position, int depth) { this->mappingBehaviourMap.insert(std::map<BaseBehaviour*, Position>::value_type(behaviour, Position(position, depth))); }

void BehaviourMapper::clear() { this->mappingBehaviourMap.clear(); }

void BehaviourMapper::destroy() { CC_SAFE_DELETE(BehaviourMapper::instance); }

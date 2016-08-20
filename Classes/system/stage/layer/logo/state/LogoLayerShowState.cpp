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
// command
#include "CommandGateway.h"
#include "BaseCommand.h"
// state
#include "LogoLayerShowState.h"
LogoLayerShowState::LogoLayerShowState() {}
LogoLayerShowState::~LogoLayerShowState() {}
void LogoLayerShowState::create() { return; }
void LogoLayerShowState::update(float delta) {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector("ui");
    for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        std::string behaviourType = behaviour->getProperty()->getType();
        BaseCommand* command = CommandGateway::getInstance()->getCommand(behaviourType);
        command->execute(behaviour, delta);
    }
    return;
}

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
#include "SimpleAudioEngine.h"

// behaviour
#include "BehaviourCollection.h"

// command
#include "CommandGateway.h"
#include "BaseCommand.h"

// state
#include "LoadingLayerShowState.h"

using namespace CocosDenshion;

LoadingLayerShowState::LoadingLayerShowState() {}

LoadingLayerShowState::~LoadingLayerShowState() {}

void LoadingLayerShowState::create() {
    SimpleAudioEngine::getInstance()->playEffect("loading_screen_jingle.mp3");
    return;
}

void LoadingLayerShowState::update(float delta) {
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
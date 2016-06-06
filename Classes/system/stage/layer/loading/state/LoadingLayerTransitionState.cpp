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
#include "BehaviourIdGenerator.h"
#include "BehaviourMapper.h"

// command
#include "CommandGateway.h"
#include "BaseCommand.h"

// geographic
#include "GeographicGateway.h"

// state
#include "LoadingLayerTransitionState.h"

// scene
#include "BattleScene.h"

// notify
#include "Notifier.h"

using namespace cocos2d;

LoadingLayerTransitionState::LoadingLayerTransitionState() {}

LoadingLayerTransitionState::~LoadingLayerTransitionState() {}

void LoadingLayerTransitionState::create() {
    this->transition(this->owner, BattleScene::SCENE_ID);
    return;
}

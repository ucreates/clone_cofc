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

// gateway
#include "GeographicGateway.h"

// notifier
#include "Notifier.h"

// scene
#include "LogoScene.h"

// state
#include "BattleTransitionState.h"

using namespace cocos2d;

BattleTransitionState::BattleTransitionState() {}

BattleTransitionState::~BattleTransitionState() {}

void BattleTransitionState::create() {
    this->transition(this->owner, LogoScene::SCENE_ID);
    return;
}

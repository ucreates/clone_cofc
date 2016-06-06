//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// scene
#include "LoadingScene.h"

// state
#include "LogoLayerTransitionState.h"

using namespace cocos2d;
LogoLayerTransitionState::LogoLayerTransitionState() {}

LogoLayerTransitionState::~LogoLayerTransitionState() {}

void LogoLayerTransitionState::create() {
    this->transition(this->owner, LoadingScene::SCENE_ID);
    return;
}

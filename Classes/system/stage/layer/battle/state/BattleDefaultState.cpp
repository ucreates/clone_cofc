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
// state
#include "BattleDefaultState.h"
using namespace cocos2d;
BattleDefaultState::BattleDefaultState() {}
BattleDefaultState::~BattleDefaultState() {}
void BattleDefaultState::create() {
    this->owner->enableInput = true;
    Layer* unitLayer = (Layer*)this->owner->getChildByTag(BaseLayer::NODE_LAYER_TAG);
    unitLayer->setScale(BattleLayer::DEFAULT_FIELD_OF_VIEW);
}
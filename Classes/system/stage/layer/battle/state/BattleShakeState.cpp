//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// math
#include "Random.h"
// state
#include "BattleShakeState.h"
using namespace cocos2d;
BattleShakeState::BattleShakeState() {}
BattleShakeState::~BattleShakeState() {}
void BattleShakeState::create() {
    Layer* unitLayer = (Layer*)this->owner->getChildByTag(BaseLayer::NODE_LAYER_TAG);
    this->defaultLayerScale = unitLayer->getScale();
    this->frame->reset();
    this->bouncy.setVerocity(BattleShakeState::SHAKE_SEED);
    this->bouncy.initialize();
}
void BattleShakeState::update(float delta) {
    Layer* unitLayer = (Layer*)this->owner->getChildByTag(BaseLayer::NODE_LAYER_TAG);
    float bound = bouncy.execute();
    float x = bound;
    float y = bound;
    int xthld = Random::create(BattleShakeState::REVERSAL_SEED);
    int ythld = Random::create(BattleShakeState::REVERSAL_SEED);
    if (0 == xthld % 2) {
        x *= -1.0f;
    }
    if (0 == ythld % 2) {
        y *= -1.0f;
    }
    Vec2 npos = unitLayer->getPosition() + Vec2(x, y);
    unitLayer->setPosition(npos);
    if (bound < 1.0f) {
        this->owner->getStateMachine()->change("default");
    }
}

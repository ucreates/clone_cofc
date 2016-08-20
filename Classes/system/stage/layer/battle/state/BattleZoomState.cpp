//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// notify
#include "Notifier.h"
#include "NotifyMessage.h"
// state
#include "BattleZoomState.h"
// vfx
#include "Exponential.h"
using namespace cocos2d;
BattleZoomState::BattleZoomState() {}
BattleZoomState::~BattleZoomState() {}
void BattleZoomState::create() { this->frame->reset(); }
void BattleZoomState::update(float delta) {
    Layer* unitLayer = (Layer*)this->owner->getChildByTag(BaseLayer::NODE_LAYER_TAG);
    float time = this->frame->getFrameTime();
    float scale = Exponential::easeOut(time, BattleZoomState::FIRST_FIELD_OF_VIEW, BattleZoomState::END_FIELD_OF_VIEW, BattleZoomState::TOTAL_TIME) + BattleLayer::FIRST_FIELD_OF_VIEW;
    if (BattleLayer::DEFAULT_FIELD_OF_VIEW <= scale) {
        unitLayer->setScale(BattleLayer::DEFAULT_FIELD_OF_VIEW);
        Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_Battle_State);
        this->complete = true;
    } else {
        unitLayer->setScale(scale);
        this->frame->update(delta);
    }
}

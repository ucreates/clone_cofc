//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BattleUITimerState.h"
#include "UIAsset.h"
#include "ServiceGateway.h"
#include "Response.h"
using namespace cocos2d::ui;
BattleUITimerState::BattleUITimerState() {
    this->timer = new SceneTimer(BattleUITimerState::GAME_TIME);
    this->persistence = true;
}
BattleUITimerState::~BattleUITimerState() { CC_SAFE_DELETE(this->timer); }
void BattleUITimerState::create() {
    UIAsset* asset = (UIAsset*)this->owner->getAsset("battle");
    this->timerText = asset->findByName<Text*>("timerText");
}
void BattleUITimerState::update(float delta) {
    std::string timeStr = this->timer->getTimeString();
    this->timerText->setString(timeStr);
    float timeNum = this->timer->getTime();
    if (0 >= timeNum) {
        this->owner->getStateMachine()->change("result");
        this->complete = true;
    }
    this->timer->update(delta);
}

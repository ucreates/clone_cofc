//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BattleUIBattleState.h"
#include "ServiceGateway.h"
#include "Response.h"
#include "UIAsset.h"
using namespace cocos2d::ui;
BattleUIBattleState::BattleUIBattleState() {}
BattleUIBattleState::~BattleUIBattleState() {}
void BattleUIBattleState::create() {
    UIAsset* asset = (UIAsset*)this->owner->getAsset("battle");
    this->overAllPercentageText = asset->findByName<Text*>("overAllPercentageText");
}
void BattleUIBattleState::update(float delta) {
    Response res = ServiceGateway::getInstance()->request("service://battle/status")->get();
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    int overAllRate = res.get<int>("overAllRate");
    this->overAllPercentageText->setString(ConvertUtility::toString(overAllRate) + "%");
    res.clear();
}

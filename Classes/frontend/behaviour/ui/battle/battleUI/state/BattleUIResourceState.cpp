//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BattleUIResourceState.h"
#include "UIAsset.h"
#include "ServiceGateway.h"
#include "Response.h"
using namespace cocos2d::ui;
BattleUIResourceState::BattleUIResourceState() { this->persistence = true; }
BattleUIResourceState::~BattleUIResourceState() {}
void BattleUIResourceState::create() {
    Response res = ServiceGateway::getInstance()->request("service://resource/info")->get();
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    UIAsset* asset = (UIAsset*)this->owner->getAsset("battle");
    this->archerCountText = asset->findByName<Text*>("archerRestCountText");
    this->barbarianCountText = asset->findByName<Text*>("barbarianRestCountText");
    this->giantCountText = asset->findByName<Text*>("giantRestCountText");
    this->goblinCountText = asset->findByName<Text*>("goblinRestCountText");
    this->wallBrakerCountText = asset->findByName<Text*>("wallBreakerRestCountText");
    this->maxElixirCountText = asset->findByName<Text*>("maxElixirCountText");
    this->maxGoldCountText = asset->findByName<Text*>("maxGoldCountText");
    int maxElixirCount = res.get<int>("maxElixirCount");
    int maxGoldCountText = res.get<int>("maxGoldCount");
    this->maxElixirCountText->setString(ConvertUtility::toString(maxElixirCount));
    this->maxGoldCountText->setString(ConvertUtility::toString(maxGoldCountText));
    res.clear();
}
void BattleUIResourceState::update(float delta) {
    Response res = ServiceGateway::getInstance()->request("service://resource/info")->get();
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    int playerArcherCount = res.get<int>("playerArcherCount");
    int playerBarbarianCount = res.get<int>("playerBarbarianCount");
    int playerGiantCount = res.get<int>("playerGiantCount");
    int playerGoblinCount = res.get<int>("playerGoblinCount");
    int playerWallBreakerCount = res.get<int>("playerWallBreakerCount");
    this->archerCountText->setString("x" + ConvertUtility::toString(playerArcherCount));
    this->barbarianCountText->setString("x" + ConvertUtility::toString(playerBarbarianCount));
    this->giantCountText->setString("x" + ConvertUtility::toString(playerGiantCount));
    this->goblinCountText->setString("x" + ConvertUtility::toString(playerGoblinCount));
    this->wallBrakerCountText->setString("x" + ConvertUtility::toString(playerWallBreakerCount));
    res.clear();
}

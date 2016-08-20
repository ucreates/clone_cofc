//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BattleUICountState.h"
#include "ConvertUtility.h"
#include "UIAsset.h"
#include "Response.h"
#include "ServiceGateway.h"
using namespace cocos2d::ui;
BattleUICountState::BattleUICountState() {
    this->lastEnemyGoldCount = 0;
    this->lastEnemyElixirCount = 0;
    this->lastPlayerEmeraldRate = BattleUICountState::MAX_RATE;
    this->lastPlayerElixirRate = BattleUICountState::MAX_RATE;
    this->lastPlayerGoldRate = BattleUICountState::MAX_RATE;
    this->currentPlayerElixirCount = 0;
    this->currentPlayerGoldCount = 0;
    this->currentPlayerEmeraldCount = 0;
    this->lastPlayerElixirCount = 0;
    this->lastPlayerGoldCount = 0;
    this->lastPlayerEmeraldCount = 0;
}
BattleUICountState::~BattleUICountState() {}
void BattleUICountState::create() {
    Response res = ServiceGateway::getInstance()->request("service://resource/info")->get();
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    this->currentEnemyElixirCount = res.get<int>("enemyElixirCount");
    this->currentEnemyGoldCount = res.get<int>("enemyGoldCount");
    this->currentPlayerEmeraldRate = res.get<float>("playerEmeraldRate");
    this->currentPlayerElixirRate = res.get<float>("playerElixirRate");
    this->currentPlayerGoldRate = res.get<float>("playerGoldRate");
    this->currentPlayerEmeraldCount = res.get<int>("playerEmeraldCount");
    this->currentPlayerElixirCount = res.get<int>("playerElixirCount");
    this->currentPlayerGoldCount = res.get<int>("playerGoldCount");
    UIAsset* asset = (UIAsset*)this->owner->getAsset("battle");
    this->lastPlayerGoldGuage = asset->findByName<LoadingBar*>("playerGoldGuage");
    this->lastPlayerElixirGuage = asset->findByName<LoadingBar*>("playerElixirGuage");
    this->lastPlayerEmeraldGuage = asset->findByName<LoadingBar*>("playerEmeraldGuage");
    this->currentPlayerElixirCountText = asset->findByName<Text*>("currentPlayerElixirCountText");
    this->currentPlayerGoldCountText = asset->findByName<Text*>("currentPlayerGoldCountText");
    this->currentPlayerEmeraldCountText = asset->findByName<Text*>("currentPlayerEmeraldCountText");
    this->enemyElixirCountText = asset->findByName<Text*>("enemyElixirCountText");
    this->enemyGoldCountText = asset->findByName<Text*>("enemyGoldCountText");
    this->enemyElixirIcon = asset->findByName<ImageView*>("enemyElixirIcon");
    this->enemyGoldIcon = asset->findByName<ImageView*>("enemyGoldIcon");
    this->playerElixirIcon = asset->findByName<ImageView*>("playerElixirIcon");
    this->playerGoldIcon = asset->findByName<ImageView*>("playerGoldIcon");
    this->playerEmeraldIcon = asset->findByName<ImageView*>("playerEmeraldIcon");
    res.clear();
    bouncy.initialize();
}
void BattleUICountState::update(float delta) {
    bool enableCount = false;
    float bound = BattleUICountState::DEFAULT_SCALE + bouncy.execute();
    if (this->lastPlayerElixirRate < this->currentPlayerElixirRate) {
        this->lastPlayerElixirRate += 1.0f;
        this->playerElixirIcon->setScale(bound, bound);
        enableCount = true;
    } else {
        this->lastPlayerElixirRate = this->currentPlayerElixirRate;
        this->playerElixirIcon->setScale(BattleUICountState::DEFAULT_SCALE, BattleUICountState::DEFAULT_SCALE);
    }
    if (this->lastPlayerEmeraldRate < this->currentPlayerEmeraldRate) {
        this->lastPlayerEmeraldRate += 1.0f;
        this->playerEmeraldIcon->setScale(bound, bound);
        enableCount = true;
    } else {
        this->lastPlayerEmeraldRate = this->currentPlayerEmeraldRate;
        this->playerEmeraldIcon->setScale(BattleUICountState::DEFAULT_SCALE, BattleUICountState::DEFAULT_SCALE);
    }
    if (this->lastPlayerGoldRate < this->currentPlayerGoldRate) {
        this->lastPlayerGoldRate += 1.0f;
        this->playerGoldIcon->setScale(bound, bound);
        enableCount = true;
    } else {
        this->lastPlayerGoldRate = this->currentPlayerGoldRate;
        this->playerGoldIcon->setScale(BattleUICountState::DEFAULT_SCALE, BattleUICountState::DEFAULT_SCALE);
    }
    if (this->lastPlayerElixirCount < this->currentPlayerElixirCount) {
        this->lastPlayerElixirCount++;
        enableCount = true;
    } else {
        this->lastPlayerElixirCount = this->currentPlayerElixirCount;
    }
    if (this->lastPlayerGoldCount < this->currentPlayerGoldCount) {
        this->lastPlayerGoldCount++;
        enableCount = true;
    } else {
        this->lastPlayerGoldCount = this->currentPlayerGoldCount;
    }
    if (this->lastPlayerEmeraldCount < this->currentPlayerEmeraldCount) {
        this->lastPlayerEmeraldCount++;
        enableCount = true;
    } else {
        this->lastPlayerEmeraldCount = this->currentPlayerEmeraldCount;
    }
    if (this->lastEnemyGoldCount > this->currentEnemyGoldCount) {
        this->lastEnemyGoldCount--;
        this->enemyGoldIcon->setScale(bound, bound);
        enableCount = true;
    } else {
        this->lastEnemyGoldCount = this->currentEnemyGoldCount;
        this->enemyGoldIcon->setScale(BattleUICountState::DEFAULT_SCALE, BattleUICountState::DEFAULT_SCALE);
    }
    if (this->lastEnemyElixirCount > this->currentEnemyElixirCount) {
        this->lastEnemyElixirCount--;
        this->enemyElixirIcon->setScale(bound, bound);
        enableCount = true;
    } else {
        this->lastEnemyElixirCount = this->currentEnemyElixirCount;
        this->enemyElixirIcon->setScale(BattleUICountState::DEFAULT_SCALE, BattleUICountState::DEFAULT_SCALE);
    }
    this->lastPlayerGoldGuage->setPercent(this->lastPlayerGoldRate);
    this->lastPlayerElixirGuage->setPercent(this->lastPlayerElixirRate);
    this->lastPlayerEmeraldGuage->setPercent(this->lastPlayerEmeraldRate);
    this->currentPlayerElixirCountText->setString(ConvertUtility::toString(this->lastPlayerElixirCount));
    this->currentPlayerGoldCountText->setString(ConvertUtility::toString(this->lastPlayerGoldCount));
    this->currentPlayerEmeraldCountText->setString(ConvertUtility::toString(this->lastPlayerEmeraldCount));
    this->enemyElixirCountText->setString(ConvertUtility::toString(this->lastEnemyElixirCount));
    this->enemyGoldCountText->setString(ConvertUtility::toString(this->lastEnemyGoldCount));
    if (false == enableCount) {
        this->owner->getStateMachine()->change("battle");
    }
}
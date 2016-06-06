//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BattleUIResultState.h"
#include "ConvertUtility.h"
#include "UIAsset.h"
#include "Response.h"
#include "ServiceGateway.h"
#include "SimpleAudioEngine.h"
#include "SoundAssetCollection.h"
#include "Notifier.h"
#include "GeographicDepth.h"

using namespace cocos2d::ui;
using namespace CocosDenshion;

BattleUIResultState::BattleUIResultState() {}

BattleUIResultState::~BattleUIResultState() {}

void BattleUIResultState::create() {
    this->complete = true;
    this->owner->getStateMachine()->stop();
    Response res = ServiceGateway::getInstance()->request("service://battle/result")->get();
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }

    int elixirCount = res.get<int>("playerElixirCount");
    int goldCount = res.get<int>("playerGoldCount");
    int emeraldCount = res.get<int>("playerEmeraldCount");
    int playerArcherCount = res.get<int>("playerArcherCount");
    int playerBarbarianCount = res.get<int>("playerBarbarianCount");
    int playerGiantCount = res.get<int>("playerGiantCount");
    int playerGoblinCount = res.get<int>("playerGoblinCount");
    int playerWallBreakerCount = res.get<int>("playerWallBreakerCount");
    int overAllRate = res.get<int>("overAllRate");

    UIAsset* asset = (UIAsset*)this->owner->getAsset("battle");
    asset->hide();

    asset = (UIAsset*)this->owner->getAsset("result");
    Text* goldText = asset->findByName<Text*>("goldText");
    Text* elixirText = asset->findByName<Text*>("elixirText");
    Text* emeraldText = asset->findByName<Text*>("emeraldText");

    Text* archerCountText = asset->findByName<Text*>("archerCountText");
    Text* barbarianCountText = asset->findByName<Text*>("barbarianCountText");
    Text* giantCountText = asset->findByName<Text*>("giantCountText");
    Text* goblinCountText = asset->findByName<Text*>("goblinCountText");
    Text* wallBrakerCountText = asset->findByName<Text*>("wallBrakerCountText");

    goldText->setString(ConvertUtility::toString(elixirCount));
    elixirText->setString(ConvertUtility::toString(goldCount));
    emeraldText->setString(ConvertUtility::toString(emeraldCount));

    archerCountText->setString("x" + ConvertUtility::toString(playerArcherCount));
    barbarianCountText->setString("x" + ConvertUtility::toString(playerBarbarianCount));
    giantCountText->setString("x" + ConvertUtility::toString(playerGiantCount));
    goblinCountText->setString("x" + ConvertUtility::toString(playerGoblinCount));
    wallBrakerCountText->setString("x" + ConvertUtility::toString(playerWallBreakerCount));

    bool battleResult = false;
    Text* resultVictoryText = asset->findByName<Text*>("resultVictoryText");
    Text* resultDefeatText = asset->findByName<Text*>("resultDefeatText");
    if (BattleUIResultState::OVERALL_LEVEL1_PERCENT <= overAllRate) {
        resultVictoryText->setVisible(true);
        resultDefeatText->setVisible(false);
        battleResult = true;
    } else {
        resultVictoryText->setVisible(false);
        resultDefeatText->setVisible(true);
    }

    Text* overAllRateText = asset->findByName<Text*>("overAllRateText");
    overAllRateText->setString(ConvertUtility::toString(overAllRate) + "%");

    ImageView* victoryStar1 = asset->findByName<ImageView*>("victoryStar1");
    if (BattleUIResultState::OVERALL_LEVEL1_PERCENT <= overAllRate) {
        victoryStar1->setVisible(true);
    } else {
        victoryStar1->setVisible(false);
    }

    ImageView* victoryStar2 = asset->findByName<ImageView*>("victoryStar2");
    if (BattleUIResultState::OVERALL_LEVEL2_PERCENT <= overAllRate) {
        victoryStar2->setVisible(true);
    } else {
        victoryStar2->setVisible(false);
    }

    ImageView* victoryStar3 = asset->findByName<ImageView*>("victoryStar3");
    if (BattleUIResultState::OVERALL_LEVEL3_PERCENT <= overAllRate) {
        victoryStar3->setVisible(true);
    } else {
        victoryStar3->setVisible(false);
    }

    asset->play("result", NULL, true);
    asset->addLayer(this->owner->layer, GeographicDepth::UI_DEPTH);
    res.clear();

    Notifier* notifier = Notifier::getInstance();
    if (false == battleResult) {
        notifier->notify(NotifyMessage::Battle_Scene_Lose_State);
    } else {
        notifier->notify(NotifyMessage::Battle_Scene_Win_State);
    }
}

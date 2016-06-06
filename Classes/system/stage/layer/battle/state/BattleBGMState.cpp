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
#include "BattleBGMState.h"

// sound
#include "BaseSoundAsset.h"
#include "SoundAssetCollection.h"

using namespace cocos2d;

BattleBGMState::BattleBGMState() {}

BattleBGMState::~BattleBGMState() {}

void BattleBGMState::create(Parameter* parameter) {
    NotifyMessage notifyMessage = parameter->get<NotifyMessage>("message");
    BaseSoundAsset* bgm = NULL;
    bool replay = true;
    if (notifyMessage == NotifyMessage::Battle_Scene_Battle_State) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        bgm = SoundAssetCollection::getInstance()->getBGMAsset("sound/bgm/combat_planning_music.ogg");
#else
        bgm = SoundAssetCollection::getInstance()->getBGMAsset("sound/bgm/combat_planning_music.mp3");
#endif
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Battle_Attack_State) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        bgm = SoundAssetCollection::getInstance()->getBGMAsset("sound/bgm/combat_music.ogg");
#else
        bgm = SoundAssetCollection::getInstance()->getBGMAsset("sound/bgm/combat_music.mp3");
#endif
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Win_State) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        bgm = SoundAssetCollection::getInstance()->getBGMAsset("sound/bgm/winwinwin.ogg");
#else
        bgm = SoundAssetCollection::getInstance()->getBGMAsset("sound/bgm/winwinwin.mp3");
#endif
        replay = false;
        this->complete = true;
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Lose_State) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        bgm = SoundAssetCollection::getInstance()->getBGMAsset("sound/bgm/battle_lost_02.ogg");
#else
        bgm = SoundAssetCollection::getInstance()->getBGMAsset("sound/bgm/battle_lost_02.mp3");
#endif
        replay = false;
        this->complete = true;
    }

    if (NULL != bgm) {
        bgm->stop();
        bgm->play(replay);
    }
}

void BattleBGMState::update(float delta) { this->owner->getStateMachine()->change("default"); }
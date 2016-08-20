//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleUICountState_h
#define BattleUICountState_h
// cocos2d
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
// state
#include "FiniteState.h"
// behaviour
#include "BattleUIBehaviour.h"
#include "Bouncy.h"
class BattleUIBehaviour;
class BattleUICountState : public FiniteState<BattleUIBehaviour> {
   public:
    BattleUICountState();
    virtual ~BattleUICountState();
    void create() override;
    void update(float delta) override;
   private:
    constexpr static const float DEFAULT_SCALE = 1.5f;
    constexpr static const float MAX_RATE = 100.0f;
    float lastPlayerGoldRate;
    float lastPlayerElixirRate;
    float lastPlayerEmeraldRate;
    float currentPlayerGoldRate;
    float currentPlayerElixirRate;
    float currentPlayerEmeraldRate;
    int lastEnemyGoldCount;
    int lastEnemyElixirCount;
    int currentEnemyGoldCount;
    int currentEnemyElixirCount;
    int currentPlayerElixirCount;
    int currentPlayerGoldCount;
    int currentPlayerEmeraldCount;
    int lastPlayerElixirCount;
    int lastPlayerGoldCount;
    int lastPlayerEmeraldCount;
    cocos2d::ui::LoadingBar* lastPlayerGoldGuage;
    cocos2d::ui::LoadingBar* lastPlayerElixirGuage;
    cocos2d::ui::LoadingBar* lastPlayerEmeraldGuage;
    cocos2d::ui::Text* currentPlayerElixirCountText;
    cocos2d::ui::Text* currentPlayerGoldCountText;
    cocos2d::ui::Text* currentPlayerEmeraldCountText;
    cocos2d::ui::Text* enemyElixirCountText;
    cocos2d::ui::Text* enemyGoldCountText;
    cocos2d::ui::ImageView* enemyElixirIcon;
    cocos2d::ui::ImageView* enemyGoldIcon;
    cocos2d::ui::ImageView* playerElixirIcon;
    cocos2d::ui::ImageView* playerGoldIcon;
    cocos2d::ui::ImageView* playerEmeraldIcon;
    Bouncy bouncy;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleUIResourceState_h
#define BattleUIResourceState_h
// cocos2d
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
// state
#include "FiniteState.h"
// behaviour
#include "BattleUIBehaviour.h"
#include "SceneTimer.h"
class BattleUIBehaviour;
class BattleUIResourceState : public FiniteState<BattleUIBehaviour> {
   public:
    BattleUIResourceState();
    virtual ~BattleUIResourceState();
    void create() override;
    void update(float delta) override;
   private:
    cocos2d::ui::Text* archerCountText;
    cocos2d::ui::Text* barbarianCountText;
    cocos2d::ui::Text* giantCountText;
    cocos2d::ui::Text* goblinCountText;
    cocos2d::ui::Text* wallBrakerCountText;
    cocos2d::ui::Text* maxElixirCountText;
    cocos2d::ui::Text* maxGoldCountText;
};
#endif

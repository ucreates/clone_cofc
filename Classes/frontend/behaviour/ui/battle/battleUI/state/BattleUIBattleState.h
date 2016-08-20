//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleUIBattleState_h
#define BattleUIBattleState_h
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
// state
#include "FiniteState.h"
// behaviour
#include "BattleUIBehaviour.h"
class BattleUIBehaviour;
class BattleUIBattleState : public FiniteState<BattleUIBehaviour> {
   public:
    BattleUIBattleState();
    virtual ~BattleUIBattleState();
    void create() override;
    void update(float delta) override;
   private:
    cocos2d::ui::Text* overAllPercentageText;
};
#endif

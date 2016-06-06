//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattleUITimerState_h
#define BattleUITimerState_h

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

class BattleUITimerState : public FiniteState<BattleUIBehaviour> {
   public:
    BattleUITimerState();
    virtual ~BattleUITimerState();
    void create() override;
    void update(float delta) override;

   private:
    static const int GAME_TIME = 120;
    SceneTimer* timer;
    cocos2d::ui::Text* timerText;
};

#endif

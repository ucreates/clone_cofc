//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattleUIBehaviour_h
#define BattleUIBehaviour_h

#include "cocos2d.h"
#include "BaseBehaviour.h"
#include "IFiniteStateMachine.h"
#include "INotify.h"
#include "BattleUIBattleState.h"
#include "BattleUIResultState.h"
#include "BattleUICountState.h"
#include "BattleUITimerState.h"
#include "BattleUIResourceState.h"

class BattleUIBattleState;
class BattleUIResultState;
class BattleUICountState;
class BattleUITimerState;
class BattleUIResourceState;

class BattleUIBehaviour : public BaseBehaviour, public IFiniteStateMachine<BattleUIBehaviour>, public INotify {
    friend BattleUIBattleState;
    friend BattleUIResultState;
    friend BattleUICountState;
    friend BattleUITimerState;
    friend BattleUIResourceState;

   public:
    BattleUIBehaviour();
    virtual ~BattleUIBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth = 0) override;
    void onUpdate(float time = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;

   private:
    void onEndBattleButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    void onPushUnitSelectButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    void setNormalButtonTexture(std::string buttonName);
    void setActiveButtonTexture(std::string buttonName);
    void updateActiveUnit(std::string buttonName);
};
#endif

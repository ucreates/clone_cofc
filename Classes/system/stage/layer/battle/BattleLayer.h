//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleLayer_h
#define BattleLayer_h
// cocos2d
#include "cocos2d.h"
// layer
#include "BaseLayer.h"
// notifier
#include "INotify.h"
// state
#include "BattleFrameState.h"
#include "BattleZoomState.h"
#include "BattleShakeState.h"
#include "BattleDefaultState.h"
#include "BattleTransitionState.h"
#include "BattleBGMState.h"
#include "BaseTransitionState.h"
#include "IFiniteStateMachine.h"
class BattleLayerBuilder;
class BattleFrameState;
class BattleZoomState;
class BattleShakeState;
class BattleDefaultState;
class BattleTransitionState;
class BattleLayer : public BaseLayer, public IFiniteStateMachine<BattleLayer>, public INotify {
    friend BattleLayerBuilder;
    friend BattleFrameState;
    friend BattleZoomState;
    friend BattleShakeState;
    friend BattleDefaultState;
    friend BattleTransitionState;
    friend BaseTransitionState<BattleLayer>;
   public:
    constexpr static const float FIRST_FIELD_OF_VIEW = 0.3f;
    constexpr static const float DEFAULT_SWIPE_SCALE_RATE = 0.1f;
    constexpr static const float DEFAULT_FIELD_OF_VIEW = 0.6f;
    static const int LAYER_ID = 3;
    bool init() override;
    void update(float delta) override;
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
    void onExit() override;
    CREATE_FUNC(BattleLayer);
};
#endif

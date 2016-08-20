//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarbarianBehaviour_h
#define BarbarianBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseUnitBehaviour.h"
// state
#include "FiniteStateMachine.h"
#include "BarbarianMoveState.h"
#include "BarbarianAttackState.h"
#include "BarbarianWinState.h"
#include "BarbarianLoseState.h"
#include "BarbarianDeadState.h"
#include "UnitMoveState.h"
#include "UnitDeadState.h"
#include "UnitWinState.h"
#include "UnitLoseState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
#include "IFiniteStateMachine.h"
class BarbarianMoveState;
class BarbarianAttackState;
class BarbarianWinState;
class BarbarianLoseState;
class BarbarianDeadState;
class BarbarianBehaviour : public BaseUnitBehaviour, public IFiniteStateMachine<BarbarianBehaviour>, public INotify {
    friend UnitMoveState<BarbarianBehaviour>;
    friend UnitDeadState<BarbarianBehaviour>;
    friend UnitLoseState<BarbarianBehaviour>;
    friend UnitWinState<BarbarianBehaviour>;
    friend BarbarianMoveState;
    friend BarbarianAttackState;
    friend BarbarianWinState;
    friend BarbarianLoseState;
    friend BarbarianDeadState;
   public:
    BarbarianBehaviour();
    virtual ~BarbarianBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif
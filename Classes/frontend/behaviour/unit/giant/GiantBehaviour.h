//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GiantBehaviour_h
#define GiantBehaviour_h

// cocos2d
#include "cocos2d.h"

// behaviour
#include "BaseUnitBehaviour.h"

// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "GiantMoveState.h"
#include "GiantAttackState.h"
#include "GiantWinState.h"
#include "GiantLoseState.h"
#include "GiantDeadState.h"
#include "UnitMoveState.h"
#include "UnitDeadState.h"
#include "UnitWinState.h"
#include "UnitLoseState.h"

// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"

class GiantMoveState;
class GiantAttackState;
class GiantWinState;
class GiantLoseState;
class GiantDeadState;
class GiantBehaviour : public BaseUnitBehaviour, public IFiniteStateMachine<GiantBehaviour>, public INotify {
    friend UnitMoveState<GiantBehaviour>;
    friend UnitDeadState<GiantBehaviour>;
    friend UnitWinState<GiantBehaviour>;
    friend UnitLoseState<GiantBehaviour>;
    friend GiantMoveState;
    friend GiantAttackState;
    friend GiantWinState;
    friend GiantLoseState;
    friend GiantDeadState;

   public:
    GiantBehaviour();
    virtual ~GiantBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};

#endif
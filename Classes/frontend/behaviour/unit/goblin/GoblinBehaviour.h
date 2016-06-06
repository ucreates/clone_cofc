//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GoblinBehaviour_h
#define GoblinBehaviour_h

// cocos2d
#include "cocos2d.h"

// behaviour
#include "BaseUnitBehaviour.h"

// state
#include "IFiniteStateMachine.h"
#include "GoblinMoveState.h"
#include "GoblinAttackState.h"
#include "GoblinWinState.h"
#include "GoblinLoseState.h"
#include "GoblinDeadState.h"
#include "UnitMoveState.h"
#include "UnitDeadState.h"
#include "UnitWinState.h"
#include "UnitLoseState.h"

// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"

class GoblinMoveState;
class GoblinAttackState;
class GoblinWinState;
class GoblinLoseState;
class GoblinDeadState;

class GoblinBehaviour : public BaseUnitBehaviour, public IFiniteStateMachine<GoblinBehaviour>, public INotify {
    friend UnitMoveState<GoblinBehaviour>;
    friend UnitDeadState<GoblinBehaviour>;
    friend UnitLoseState<GoblinBehaviour>;
    friend UnitWinState<GoblinBehaviour>;
    friend GoblinMoveState;
    friend GoblinAttackState;
    friend GoblinWinState;
    friend GoblinLoseState;
    friend GoblinDeadState;

   public:
    GoblinBehaviour();
    virtual ~GoblinBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};

#endif
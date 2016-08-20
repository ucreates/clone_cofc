//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef WallBreakerBehaviour_h
#define WallBreakerBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseUnitBehaviour.h"
// state
#include "IFiniteStateMachine.h"
#include "WallBreakerMoveState.h"
#include "WallBreakerAttackState.h"
#include "WallBreakerWinState.h"
#include "WallBreakerLoseState.h"
#include "WallBreakerDeadState.h"
#include "UnitMoveState.h"
#include "UnitDeadState.h"
#include "UnitLoseState.h"
#include "UnitWinState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
class WallBreakerMoveState;
class WallBreakerAttackState;
class WallBreakerWinState;
class WallBreakerLoseState;
class WallBreakerDeadState;
class WallBreakerBehaviour : public BaseUnitBehaviour, public IFiniteStateMachine<WallBreakerBehaviour>, public INotify {
    friend UnitMoveState<WallBreakerBehaviour>;
    friend UnitDeadState<WallBreakerBehaviour>;
    friend UnitLoseState<WallBreakerBehaviour>;
    friend UnitWinState<WallBreakerBehaviour>;
    friend WallBreakerMoveState;
    friend WallBreakerAttackState;
    friend WallBreakerWinState;
    friend WallBreakerLoseState;
    friend WallBreakerDeadState;
   public:
    WallBreakerBehaviour();
    virtual ~WallBreakerBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif

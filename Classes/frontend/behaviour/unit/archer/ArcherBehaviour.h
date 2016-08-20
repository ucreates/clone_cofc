//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ArcherBehaviour_h
#define ArcherBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseUnitBehaviour.h"
// state
#include "FiniteStateMachine.h"
#include "ArcherMoveState.h"
#include "ArcherAttackState.h"
#include "ArcherWinState.h"
#include "ArcherLoseState.h"
#include "ArcherDeadState.h"
#include "UnitMoveState.h"
#include "UnitDeadState.h"
#include "UnitWinState.h"
#include "UnitLoseState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
#include "IFiniteStateMachine.h"
class ArcherMoveState;
class ArcherAttackState;
class ArcherWinState;
class ArcherLoseState;
class ArcherDeadState;
class ArcherBehaviour : public BaseUnitBehaviour, public IFiniteStateMachine<ArcherBehaviour>, public INotify {
    friend UnitMoveState<ArcherBehaviour>;
    friend UnitDeadState<ArcherBehaviour>;
    friend UnitLoseState<ArcherBehaviour>;
    friend UnitWinState<ArcherBehaviour>;
    friend ArcherMoveState;
    friend ArcherAttackState;
    friend ArcherWinState;
    friend ArcherLoseState;
    friend ArcherDeadState;
   public:
    ArcherBehaviour();
    virtual ~ArcherBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif

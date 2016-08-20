//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef MortarBehaviour_h
#define MortarBehaviour_h
// behaviour
#include "BaseBarrierBehaviour.h"
// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "MortarAttackState.h"
#include "MortarDestroyState.h"
#include "MortarDamageState.h"
#include "MortarPauseState.h"
#include "MortarTouchBeganState.h"
#include "MortarTouchEndState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
// geography
#include "GeographicNode.h"
class MortarAttackState;
class MortarDestroyState;
class MortarDamageState;
class MortarPauseState;
class MortarTouchBeganState;
class MortarTouchEndState;
class MortarBehaviour : public BaseBarrierBehaviour, public IFiniteStateMachine<MortarBehaviour>, public INotify {
    friend MortarAttackState;
    friend MortarDestroyState;
    friend MortarDamageState;
    friend MortarPauseState;
    friend MortarTouchBeganState;
    friend MortarTouchEndState;
   public:
    MortarBehaviour(GeographicNode* geographicNode);
    virtual ~MortarBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth) override;
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif
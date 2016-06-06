//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ElixirTankBehaviour_h
#define ElixirTankBehaviour_h

// behaviour
#include "BaseBarrierBehaviour.h"

// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "ElixirTankDestroyState.h"
#include "ElixirTankDamageState.h"
#include "ElixirTankTouchBeganState.h"
#include "ElixirTankTouchEndState.h"

// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"

// geography
#include "GeographicNode.h"

class ElixirTankDestroyState;
class ElixirTankDamageState;
class ElixirTankTouchBeganState;
class ElixirTankTouchEndState;

class ElixirTankBehaviour : public BaseBarrierBehaviour, public IFiniteStateMachine<ElixirTankBehaviour>, public INotify {
    friend ElixirTankDestroyState;
    friend ElixirTankDamageState;
    friend ElixirTankTouchBeganState;
    friend ElixirTankTouchEndState;

   public:
    ElixirTankBehaviour(GeographicNode* geographicNode);
    virtual ~ElixirTankBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth) override;
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TurretBehaviour_h
#define TurretBehaviour_h

// behaviour
#include "BaseBarrierBehaviour.h"
#include "BaseBehaviour.h"

// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "TurretDestroyState.h"
#include "TurretDamageState.h"
#include "TurretTouchBeganState.h"
#include "TurretTouchEndState.h"

// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"

// geography
#include "GeographicNode.h"

class TurretDestroyState;
class TurretDamageState;
class TurretTouchBeganState;
class TurretTouchEndState;

class TurretBehaviour : public BaseBarrierBehaviour, public IFiniteStateMachine<TurretBehaviour>, public INotify {
    friend TurretDestroyState;
    friend TurretDamageState;
    friend TurretTouchBeganState;
    friend TurretTouchEndState;

   public:
    TurretBehaviour(GeographicNode* geographicNode);
    virtual ~TurretBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth) override;
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
    BaseBehaviour* unit;
};

#endif
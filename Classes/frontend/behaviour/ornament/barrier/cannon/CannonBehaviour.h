//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef CannonBehaviour_h
#define CannonBehaviour_h

// behaviour
#include "BaseBarrierBehaviour.h"

// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "CannonAttackState.h"
#include "CannonSearchState.h"
#include "CannonDamageState.h"
#include "CannonDestroyState.h"
#include "CannonTouchBeganState.h"
#include "CannonTouchEndState.h"

// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"

// geography
#include "GeographicNode.h"

class CannonAttackState;
class CannonSearchState;
class CannonDestroyState;
class CannonDamageState;
class CannonTouchBeganState;
class CannonTouchEndState;

class CannonBehaviour : public BaseBarrierBehaviour, public IFiniteStateMachine<CannonBehaviour>, public INotify {
    friend CannonAttackState;
    friend CannonSearchState;
    friend CannonDestroyState;
    friend CannonDamageState;
    friend CannonTouchBeganState;
    friend CannonTouchEndState;

   public:
    CannonBehaviour(GeographicNode* geographicNode);
    virtual ~CannonBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth) override;
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};

#endif
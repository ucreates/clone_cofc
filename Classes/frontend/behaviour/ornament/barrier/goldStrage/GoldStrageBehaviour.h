//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GoldStrageBehaviour_h
#define GoldStrageBehaviour_h
// behaviour
#include "BaseBarrierBehaviour.h"
// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "GoldStrageDestroyState.h"
#include "GoldStrageDamageState.h"
#include "GoldStrageTouchBeganState.h"
#include "GoldStrageTouchEndState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
// geography
#include "GeographicNode.h"
class GoldStrageDestroyState;
class GoldStrageDamageState;
class GoldStrageTouchBeganState;
class GoldStrageTouchEndState;
class GoldStrageBehaviour : public BaseBarrierBehaviour, public IFiniteStateMachine<GoldStrageBehaviour>, public INotify {
    friend GoldStrageDestroyState;
    friend GoldStrageDamageState;
    friend GoldStrageTouchBeganState;
    friend GoldStrageTouchEndState;
   public:
    GoldStrageBehaviour(GeographicNode* geographicNode);
    virtual ~GoldStrageBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth) override;
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif
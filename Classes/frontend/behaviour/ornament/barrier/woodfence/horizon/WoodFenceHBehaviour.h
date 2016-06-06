//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WoodFenceHBehaviour_h
#define WoodFenceHBehaviour_h

// behaviour
#include "BaseBarrierBehaviour.h"

// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "WoodFenceHDestroyState.h"
#include "WoodFenceHDamageState.h"
#include "WoodFenceHTouchBeganState.h"
#include "WoodFenceHTouchEndState.h"

// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"

// geography
#include "GeographicNode.h"

class WoodFenceHDestroyState;
class WoodFenceHDamageState;
class WoodFenceHTouchBeganState;
class WoodFenceHTouchEndState;
class WoodFenceHBehaviour : public BaseBarrierBehaviour, public IFiniteStateMachine<WoodFenceHBehaviour>, public INotify {
    friend WoodFenceHDestroyState;
    friend WoodFenceHDamageState;
    friend WoodFenceHTouchBeganState;
    friend WoodFenceHTouchEndState;

   public:
    WoodFenceHBehaviour(GeographicNode* geographicNode);
    virtual ~WoodFenceHBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth) override;
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};

#endif
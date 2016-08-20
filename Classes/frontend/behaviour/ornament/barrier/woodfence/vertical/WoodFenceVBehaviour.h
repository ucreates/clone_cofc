//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef WoodFenceVBehaviour_h
#define WoodFenceVBehaviour_h
// behaviour
#include "BaseBarrierBehaviour.h"
// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "WoodFenceVDestroyState.h"
#include "WoodFenceVDamageState.h"
#include "WoodFenceVTouchBeganState.h"
#include "WoodFenceVTouchEndState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
// geography
#include "GeographicNode.h"
class WoodFenceVDestroyState;
class WoodFenceVDamageState;
class WoodFenceVTouchBeganState;
class WoodFenceVTouchEndState;
class WoodFenceVBehaviour : public BaseBarrierBehaviour, public IFiniteStateMachine<WoodFenceVBehaviour>, public INotify {
    friend WoodFenceVDestroyState;
    friend WoodFenceVDamageState;
    friend WoodFenceVTouchBeganState;
    friend WoodFenceVTouchEndState;
   public:
    WoodFenceVBehaviour(GeographicNode* geographicNode);
    virtual ~WoodFenceVBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth) override;
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif
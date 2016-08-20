//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GraveBehaviour_h
#define GraveBehaviour_h
// behaviour
#include "BaseOrnamentBehaviour.h"
// state
#include "FiniteStateMachine.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
// geography
#include "GeographicNode.h"
class GraveBehaviour : public BaseOrnamentBehaviour {
   public:
    GraveBehaviour(GeographicNode* geographicNode);
    virtual ~GraveBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
};
#endif

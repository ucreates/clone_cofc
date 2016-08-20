//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ArrowBehaviour_h
#define ArrowBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseBehaviour.h"
// state
#include "IFiniteStateMachine.h"
#include "ArrowActiveBezier2DState.h"
#include "ArrowActiveBezier3DState.h"
#include "ArrowDestroyState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
// geography
#include "GeographicNode.h"
class ArrowActiveBezier2DState;
class ArrowActiveBezier3DState;
class ArrowDestroyState;
class ArrowBehaviour : public BaseBehaviour, public IFiniteStateMachine<ArrowBehaviour>, public INotify {
    friend ArrowActiveBezier2DState;
    friend ArrowActiveBezier3DState;
    friend ArrowDestroyState;
   public:
    ArrowBehaviour(GeographicNode* start, GeographicNode* goal, int ownerId, float paddingHeight = 0.0f, bool isEnemy = false, bool debug = false);
    virtual ~ArrowBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
    void setProperty(GeographicNode* start, GeographicNode* goal, float paddingHeight = 0.0f, bool isEnemy = false, bool debug = false);
   private:
    GeographicNode* start;
    GeographicNode* goal;
    float paddingHeight;
    bool debug;
};
#endif

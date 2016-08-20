//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef MortarBulletBehaviour_h
#define MortarBulletBehaviour_h
// cocos2d
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
// behaviour
#include "BaseBehaviour.h"
// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "MortarBulletActiveState.h"
#include "MortarBulletDestroyState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
// geography
#include "GeographicNode.h"
class MortarBulletActiveState;
class MortarBulletDestroyState;
class MortarBulletBehaviour : public BaseBehaviour, public IFiniteStateMachine<MortarBulletBehaviour>, public INotify {
    friend MortarBulletActiveState;
    friend MortarBulletDestroyState;
   public:
    MortarBulletBehaviour(GeographicNode* start, GeographicNode* goal, int ownerId, bool debug = false);
    virtual ~MortarBulletBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
    void setProperty(GeographicNode* start, GeographicNode* goal, bool debug = false);
   private:
    GeographicNode* start;
    GeographicNode* goal;
    bool debug;
};
#endif
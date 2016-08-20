//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef CannonBulletBehaviour_h
#define CannonBulletBehaviour_h
// behaviour
#include "BaseBehaviour.h"
// state
#include "IFiniteStateMachine.h"
#include "CannonBulletActiveState.h"
#include "CannonBulletDestroyState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
// geography
#include "GeographicNode.h"
class CannonBulletActiveState;
class CannonBulletDestroyState;
class CannonBulletBehaviour : public BaseBehaviour, public IFiniteStateMachine<CannonBulletBehaviour>, public INotify {
    friend CannonBulletActiveState;
    friend CannonBulletDestroyState;
   public:
    CannonBulletBehaviour(GeographicNode* node, int ownerId, float degree, bool debug = false);
    virtual ~CannonBulletBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
    void setProperty(GeographicNode* node, float degree, bool debug = false);
   private:
    GeographicNode* start;
    GeographicNode* goal;
    bool debug;
    int degree;
};
#endif
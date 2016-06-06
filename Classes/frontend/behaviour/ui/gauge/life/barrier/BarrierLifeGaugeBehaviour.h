//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BarrierLifeGaugeBehaviour_h
#define BarrierLifeGaugeBehaviour_h

// cocos2d
#include "cocos2d.h"

// behaviour
#include "BaseBehaviour.h"

// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "BarrierLifeGaugeMoveState.h"
#include "BarrierLifeGaugeShowState.h"

// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"

class BarrierLifeGaugeMoveState;
class BarrierLifeGaugeShowState;

class BarrierLifeGaugeBehaviour : public BaseBehaviour, public IFiniteStateMachine<BarrierLifeGaugeBehaviour>, public INotify {
    friend BarrierLifeGaugeMoveState;
    friend BarrierLifeGaugeShowState;

   public:
    BarrierLifeGaugeBehaviour(BaseBehaviour* owner);
    virtual ~BarrierLifeGaugeBehaviour();
    void onCreate(cocos2d::Layer* layer, int depth = 0) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;

   private:
    BaseBehaviour* unit;
};

#endif
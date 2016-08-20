//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UnitLifeGaugeBehaviour_h
#define UnitLifeGaugeBehaviour_h
// behaviour
#include "BaseBehaviour.h"
#include "BaseUnitBehaviour.h"
// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "UnitLifeGaugeMoveState.h"
#include "UnitLifeGaugeShowState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
class BaseUnitBehaviour;
class UnitLifeGaugeMoveState;
class UnitLifeGaugeShowState;
class UnitLifeGaugeBehaviour : public BaseBehaviour, public IFiniteStateMachine<UnitLifeGaugeBehaviour>, public INotify {
    friend BaseUnitBehaviour;
    friend UnitLifeGaugeMoveState;
    friend UnitLifeGaugeShowState;
   public:
    UnitLifeGaugeBehaviour(BaseBehaviour* owner);
    virtual ~UnitLifeGaugeBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
   private:
    BaseBehaviour* unit;
};
#endif
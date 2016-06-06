//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WallBreakerAttackState_h
#define WallBreakerAttackState_h

// state
#include "FiniteState.h"

// behaviour
#include "WallBreakerBehaviour.h"

// notify
#include "Parameter.h"
#include "BaseStrategy.h"

class WallBreakerBehaviour;
class WallBreakerAttackState : public FiniteState<WallBreakerBehaviour> {
   public:
    WallBreakerAttackState();
    virtual ~WallBreakerAttackState();
    void create(Parameter* parameter) override;
    void update(float delta) override;

   private:
    const int ENABLE_ATTACK_DISTANCE = 1;
    constexpr static const float WAIT_TIME = 3.0f;
    BaseRenderAsset* asset;
    GeographicNode* barrierNode;
    int targetBarrierId;
    void changeDirection();
    void selectAttackAnimation(std::string animationNamem, bool transform);
};

#endif

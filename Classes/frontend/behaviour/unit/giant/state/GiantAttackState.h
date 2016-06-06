//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GiantAttackState_h
#define GiantAttackState_h

// cocos2d
#include "cocos2d.h"

// state
#include "FiniteState.h"

// behaviour
#include "GiantBehaviour.h"
#include "BaseOrnamentBehaviour.h"
#include "BaseStrategy.h"

class GiantBehaviour;
class GiantAttackState : public FiniteState<GiantBehaviour> {
   public:
    GiantAttackState();
    virtual ~GiantAttackState();
    void create(Parameter* parameter) override;
    void update(float delta = 0.0f) override;

   private:
    const int ENABLE_ATTACK_DISTANCE = 1;
    constexpr static const float WAIT_TIME = 1.0f;
    BaseRenderAsset* asset;
    GeographicNode* barrierNode;
    int targetBarrierId;
    BaseOrnamentBehaviour* targetBarrier;
    bool destroy;
    BaseStrategy* damageStrategy;
    void changeDirection();
    void selectAttackAnimation(std::string animationNamem, bool transform);
};

#endif

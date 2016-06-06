//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GoblinAttackState_h
#define GoblinAttackState_h

// cocos2d
#include "cocos2d.h"

// state
#include "FiniteState.h"

// behaviour
#include "GoblinBehaviour.h"
#include "BaseOrnamentBehaviour.h"
#include "BaseStrategy.h"

class GoblinBehaviour;

class GoblinAttackState : public FiniteState<GoblinBehaviour> {
   public:
    GoblinAttackState();
    virtual ~GoblinAttackState();
    void create(Parameter* parameter) override;
    void update(float delta = 0.0f) override;

   private:
    const int ENABLE_ATTACK_DISTANCE = 1;
    constexpr static const float WAIT_TIME = 0.5f;
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

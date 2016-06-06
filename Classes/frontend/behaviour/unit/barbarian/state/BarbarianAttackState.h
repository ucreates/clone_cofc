//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BarbarianAttackState_h
#define BarbarianAttackState_h

// stl
#include <vector>

// cocos2d
#include "cocos2d.h"

// state
#include "FiniteState.h"

// behaviour
#include "BarbarianBehaviour.h"
#include "BaseOrnamentBehaviour.h"

// frame
#include "TimeLine.h"

// notify
#include "Parameter.h"
#include "BaseStrategy.h"

class BarbarianBehaviour;

class BarbarianAttackState : public FiniteState<BarbarianBehaviour> {
   public:
    BarbarianAttackState();
    virtual ~BarbarianAttackState();
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

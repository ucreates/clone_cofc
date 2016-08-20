//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef CannonAttackState_h
#define CannonAttackState_h
// stl
#include <vector>
// state
#include "FiniteState.h"
// behaviour
#include "CannonBehaviour.h"
#include "CannonBulletBehaviour.h"
// route
#include "BaseRouteSearch.h"
// frame
#include "TimeLine.h"
#include "Position.h"
class CannonBehaviour;
class CannonAttackState : public FiniteState<CannonBehaviour> {
   public:
    CannonAttackState(int ownerId);
    virtual ~CannonAttackState();
    void create(Parameter* parameter) override;
    void update(float delta) override;
   private:
    constexpr static const float TRANSFORM_TIME = 0.1f;
    constexpr static const float SHOT_TIME = 2.0f;
    const int STOCKED_BULLET_NUMBER = 1;
    TimeLine* shotFrame;
    Position origin;
    Position destination;
    float sin;
    float cos;
    int degree;
    float shotDegree;
    std::vector<CannonBulletBehaviour*> stockedBulletVector;
    int stocledBulletCount;
};
#endif

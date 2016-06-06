//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WallBreakerMoveState_h
#define WallBreakerMoveState_h

// behaviour
#include "WallBreakerBehaviour.h"

// state
#include "FiniteState.h"
#include "UnitMoveState.h"

class WallBreakerBehaviour;
class WallBreakerMoveState : public FiniteState<WallBreakerBehaviour>, UnitMoveState<WallBreakerBehaviour> {
   public:
    WallBreakerMoveState();
    virtual ~WallBreakerMoveState();
    void create() override;
    void update(float delta) override;

   protected:
    GeographicNode* findGoalNode(GeographicNode* startNode) override;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GiantMoveState_h
#define GiantMoveState_h

// state
#include "FiniteState.h"
#include "UnitMoveState.h"

// behaviour
#include "GiantBehaviour.h"

class GiantBehaviour;
class GiantMoveState : public FiniteState<GiantBehaviour>, UnitMoveState<GiantBehaviour> {
   public:
    GiantMoveState();
    virtual ~GiantMoveState();
    void create() override;
    void update(float delta) override;

   protected:
    GeographicNode* findGoalNode(GeographicNode* startNode) override;
};

#endif

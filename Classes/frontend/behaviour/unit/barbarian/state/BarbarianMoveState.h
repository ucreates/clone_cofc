//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BarbarianMoveState_h
#define BarbarianMoveState_h

// state
#include "FiniteState.h"
#include "UnitMoveState.h"

// behaviour
#include "BarbarianBehaviour.h"

class BarbarianBehaviour;
class BarbarianMoveState : public FiniteState<BarbarianBehaviour>, UnitMoveState<BarbarianBehaviour> {
   public:
    BarbarianMoveState();
    virtual ~BarbarianMoveState();
    void create() override;
    void update(float delta) override;
};

#endif

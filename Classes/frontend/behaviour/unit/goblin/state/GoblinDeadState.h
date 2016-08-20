//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GoblinDeadState_h
#define GoblinDeadState_h
// state
#include "FiniteState.h"
#include "UnitDeadState.h"
// behaviour
#include "GoblinBehaviour.h"
class GoblinBehaviour;
class GoblinDeadState : public FiniteState<GoblinBehaviour>, UnitDeadState<GoblinBehaviour> {
   public:
    GoblinDeadState();
    virtual ~GoblinDeadState();
    void create() override;
};
#endif

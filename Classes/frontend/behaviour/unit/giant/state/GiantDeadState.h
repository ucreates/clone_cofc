//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GiantDeadState_h
#define GiantDeadState_h

// state
#include "FiniteState.h"
#include "UnitDeadState.h"

// behaviour
#include "GiantBehaviour.h"

class GiantBehaviour;
class GiantDeadState : public FiniteState<GiantBehaviour>, UnitDeadState<GiantBehaviour> {
   public:
    GiantDeadState();
    virtual ~GiantDeadState();
    void create() override;
};

#endif

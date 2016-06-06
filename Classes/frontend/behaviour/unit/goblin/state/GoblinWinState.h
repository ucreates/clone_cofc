//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GoblinWinState_h
#define GoblinWinState_h

// state
#include "FiniteState.h"
#include "UnitWinState.h"

// behaviour
#include "GoblinBehaviour.h"

class GoblinBehaviour;
class GoblinWinState : public FiniteState<GoblinBehaviour>, UnitWinState<GoblinBehaviour> {
   public:
    GoblinWinState();
    virtual ~GoblinWinState();
    void create() override;
};

#endif

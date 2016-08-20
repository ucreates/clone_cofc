//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef WallBreakerDeadState_h
#define WallBreakerDeadState_h
// state
#include "FiniteState.h"
#include "UnitDeadState.h"
// behaviour
#include "WallBreakerBehaviour.h"
class WallBreakerBehaviour;
class WallBreakerDeadState : public FiniteState<WallBreakerBehaviour>, UnitDeadState<WallBreakerBehaviour> {
   public:
    WallBreakerDeadState();
    virtual ~WallBreakerDeadState();
    void create() override;
};
#endif

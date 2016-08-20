//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef WallBreakerWinState_h
#define WallBreakerWinState_h
// state
#include "FiniteState.h"
#include "UnitWinState.h"
// behaviour
#include "WallBreakerBehaviour.h"
class WallBreakerBehaviour;
class WallBreakerWinState : public FiniteState<WallBreakerBehaviour>, UnitWinState<WallBreakerBehaviour> {
   public:
    WallBreakerWinState();
    virtual ~WallBreakerWinState();
    void create() override;
};
#endif

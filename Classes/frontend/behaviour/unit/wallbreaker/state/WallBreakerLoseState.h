//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WallBreakerLoseState_h
#define WallBreakerLoseState_h

// state
#include "FiniteState.h"
#include "UnitLoseState.h"

// behaviour
#include "WallBreakerBehaviour.h"

// asset
#include "AnimatorAsset.h"

class WallBreakerBehaviour;
class WallBreakerLoseState : public FiniteState<WallBreakerBehaviour>, UnitLoseState<WallBreakerBehaviour> {
   public:
    WallBreakerLoseState();
    virtual ~WallBreakerLoseState();
    void create() override;
};

#endif

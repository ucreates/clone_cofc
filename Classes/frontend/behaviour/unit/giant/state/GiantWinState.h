//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GiantWinState_h
#define GiantWinState_h

// state
#include "FiniteState.h"
#include "UnitWinState.h"

// behaviour
#include "GiantBehaviour.h"

// asset
#include "AnimatorAsset.h"

class GiantBehaviour;
class GiantWinState : public FiniteState<GiantBehaviour>, UnitWinState<GiantBehaviour> {
   public:
    GiantWinState();
    virtual ~GiantWinState();
    void create() override;
};

#endif

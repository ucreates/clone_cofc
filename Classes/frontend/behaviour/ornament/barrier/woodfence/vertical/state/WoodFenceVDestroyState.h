//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WoodFenceVDestroyState_h
#define WoodFenceVDestroyState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "WoodFenceVBehaviour.h"

// route
#include "BaseRouteSearch.h"

// frame
#include "TimeLine.h"
#include "BarrierDestroyState.h"

class WoodFenceVBehaviour;
class WoodFenceVDestroyState : public FiniteState<WoodFenceVBehaviour>, BarrierDestroyState<WoodFenceVBehaviour> {
   public:
    WoodFenceVDestroyState();
    virtual ~WoodFenceVDestroyState();
    void create() override;

   private:
    BaseStrategy* destroyStrategy;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WoodFenceHDestroyState_h
#define WoodFenceHDestroyState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "WoodFenceHBehaviour.h"

// route
#include "BaseRouteSearch.h"

// frame
#include "TimeLine.h"
#include "BarrierDestroyState.h"

class WoodFenceHBehaviour;
class WoodFenceHDestroyState : public FiniteState<WoodFenceHBehaviour>, BarrierDestroyState<WoodFenceHBehaviour> {
   public:
    WoodFenceHDestroyState();
    virtual ~WoodFenceHDestroyState();
    void create() override;

   private:
    BaseStrategy* destroyStrategy;
};

#endif

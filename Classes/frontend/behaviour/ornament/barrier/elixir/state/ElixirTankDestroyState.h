//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ElixirTankDestroyState_h
#define ElixirTankDestroyState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "ElixirTankBehaviour.h"

// route
#include "BaseRouteSearch.h"

// frame
#include "TimeLine.h"
#include "BarrierDestroyState.h"
#include "BaseStrategy.h"

class ElixirTankBehaviour;
class ElixirTankDestroyState : public FiniteState<ElixirTankBehaviour>, BarrierDestroyState<ElixirTankBehaviour> {
   public:
    ElixirTankDestroyState();
    ~ElixirTankDestroyState();
    void create() override;

   private:
    BaseStrategy* destroyStrategy;
};

#endif

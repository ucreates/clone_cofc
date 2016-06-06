//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef MortarDestroyState_h
#define MortarDestroyState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "MortarBehaviour.h"

// route
#include "BaseRouteSearch.h"

// frame
#include "TimeLine.h"
#include "BarrierDestroyState.h"

class MortarBehaviour;

class MortarDestroyState : public FiniteState<MortarBehaviour>, BarrierDestroyState<MortarBehaviour> {
   public:
    MortarDestroyState();
    virtual ~MortarDestroyState();
    void create() override;

   private:
    BaseStrategy* destroyStrategy;
};

#endif

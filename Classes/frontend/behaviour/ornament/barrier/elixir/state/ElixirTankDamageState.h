//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ElixirTankDamageState_h
#define ElixirTankDamageState_h

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
#include "BaseStrategy.h"

class ElixirTankBehaviour;

class ElixirTankDamageState : public FiniteState<ElixirTankBehaviour> {
   public:
    ElixirTankDamageState();
    ~ElixirTankDamageState();
    void create(Parameter* parameter) override;

   private:
    BaseStrategy* damageStrategy;
};

#endif

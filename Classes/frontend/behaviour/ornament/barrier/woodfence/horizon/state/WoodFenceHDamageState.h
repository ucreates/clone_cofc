//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WoodFenceHDamageState_h
#define WoodFenceHDamageState_h

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

#include "Parameter.h"

class WoodFenceHBehaviour;
class WoodFenceHDamageState : public FiniteState<WoodFenceHBehaviour> {
   public:
    WoodFenceHDamageState();
    virtual ~WoodFenceHDamageState();
    void create(Parameter* parameter) override;

   private:
    BaseStrategy* damageStrategy;
};

#endif

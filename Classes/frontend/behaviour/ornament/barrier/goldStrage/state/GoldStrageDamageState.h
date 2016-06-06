//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GoldStrageDamageState_h
#define GoldStrageDamageState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "GoldStrageBehaviour.h"

// route
#include "BaseRouteSearch.h"

// frame
#include "TimeLine.h"

#include "Parameter.h"

class GoldStrageBehaviour;
class GoldStrageDamageState : public FiniteState<GoldStrageBehaviour> {
   public:
    GoldStrageDamageState();
    virtual ~GoldStrageDamageState();
    void create(Parameter* parameter) override;

   private:
    BaseStrategy* damageStrategy;
};

#endif

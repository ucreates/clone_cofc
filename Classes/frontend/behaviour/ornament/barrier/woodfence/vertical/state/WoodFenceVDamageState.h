//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef WoodFenceVDamageState_h
#define WoodFenceVDamageState_h
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
#include "Parameter.h"
class WoodFenceVBehaviour;
class WoodFenceVDamageState : public FiniteState<WoodFenceVBehaviour> {
   public:
    WoodFenceVDamageState();
    virtual ~WoodFenceVDamageState();
    void create(Parameter* parameter) override;
   private:
    BaseStrategy* damageStrategy;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GoldStrageDestroyState_h
#define GoldStrageDestroyState_h
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
#include "BarrierDestroyState.h"
class GoldStrageBehaviour;
class GoldStrageDestroyState : public FiniteState<GoldStrageBehaviour>, BarrierDestroyState<GoldStrageBehaviour> {
   public:
    GoldStrageDestroyState();
    virtual ~GoldStrageDestroyState();
    void create() override;
   private:
    BaseStrategy* destroyStrategy;
};
#endif

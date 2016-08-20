//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef CannonDestroyState_h
#define CannonDestroyState_h
// stl
#include <vector>
// state
#include "FiniteState.h"
// behaviour
#include "CannonBehaviour.h"
// route
#include "BaseRouteSearch.h"
// frame
#include "TimeLine.h"
#include "BarrierDestroyState.h"
class CannonBehaviour;
class CannonDestroyState : public FiniteState<CannonBehaviour>, BarrierDestroyState<CannonBehaviour> {
   public:
    CannonDestroyState();
    virtual ~CannonDestroyState();
    void create() override;
   private:
    BaseStrategy* destroyStrategy;
};
#endif

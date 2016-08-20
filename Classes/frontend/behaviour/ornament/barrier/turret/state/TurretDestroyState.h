//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TurretDestroyState_h
#define TurretDestroyState_h
// stl
#include <vector>
// state
#include "FiniteState.h"
// behaviour
#include "TurretBehaviour.h"
// route
#include "BaseRouteSearch.h"
// frame
#include "TimeLine.h"
#include "BarrierDestroyState.h"
class TurretBehaviour;
class TurretDestroyState : public FiniteState<TurretBehaviour>, BarrierDestroyState<TurretBehaviour> {
   public:
    TurretDestroyState();
    virtual ~TurretDestroyState();
    void create() override;
   private:
    BaseStrategy* destoryStrategy;
};
#endif

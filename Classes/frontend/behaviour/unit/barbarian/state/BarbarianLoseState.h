//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarbarianLoseState_h
#define BarbarianLoseState_h
// state
#include "FiniteState.h"
#include "UnitLoseState.h"
// behaviour
#include "BarbarianBehaviour.h"
// route
#include "BaseRouteSearch.h"
// frame
#include "TimeLine.h"
// asset
#include "AnimatorAsset.h"
class BarbarianBehaviour;
class BarbarianLoseState : public FiniteState<BarbarianBehaviour>, UnitLoseState<BarbarianBehaviour> {
   public:
    BarbarianLoseState();
    virtual ~BarbarianLoseState();
    void create() override;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ElixirTankTouchEndState_h
#define ElixirTankTouchEndState_h
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
// asset
#include "AnimatorAsset.h"
class ElixirTankBehaviour;
class ElixirTankTouchEndState : public FiniteState<ElixirTankBehaviour> {
   public:
    ElixirTankTouchEndState();
    ~ElixirTankTouchEndState();
    void create(Parameter* parameter) override;
   private:
    AnimatorAsset* asset;
};
#endif

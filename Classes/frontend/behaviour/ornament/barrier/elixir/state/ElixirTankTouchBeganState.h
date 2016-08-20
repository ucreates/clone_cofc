//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ElixirTankTouchBeganState_h
#define ElixirTankTouchBeganState_h
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
class ElixirTankTouchBeganState : public FiniteState<ElixirTankBehaviour> {
   public:
    ElixirTankTouchBeganState();
    ~ElixirTankTouchBeganState();
    void create(Parameter* parameter) override;
   private:
    AnimatorAsset* asset;
};
#endif

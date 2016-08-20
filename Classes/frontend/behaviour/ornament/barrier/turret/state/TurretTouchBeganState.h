//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TurretTouchBeganState_h
#define TurretTouchBeganState_h
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
// asset
#include "AnimatorAsset.h"
class TurretBehaviour;
class TurretTouchBeganState : public FiniteState<TurretBehaviour> {
   public:
    TurretTouchBeganState();
    virtual ~TurretTouchBeganState();
    void create(Parameter* parameter);
   private:
    AnimatorAsset* asset;
};
#endif

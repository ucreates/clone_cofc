//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TurretTouchEndState_h
#define TurretTouchEndState_h

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
class TurretTouchEndState : public FiniteState<TurretBehaviour> {
   public:
    TurretTouchEndState();
    virtual ~TurretTouchEndState();
    void create(Parameter* parameter);

   private:
    AnimatorAsset* asset;
};

#endif

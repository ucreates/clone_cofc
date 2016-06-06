//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WoodFenceVTouchEndState_h
#define WoodFenceVTouchEndState_h

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

// asset
#include "AnimatorAsset.h"

class WoodFenceVBehaviour;
class WoodFenceVTouchEndState : public FiniteState<WoodFenceVBehaviour> {
   public:
    WoodFenceVTouchEndState();
    virtual ~WoodFenceVTouchEndState();
    void create(Parameter* parameter);

   private:
    AnimatorAsset* asset;
};

#endif

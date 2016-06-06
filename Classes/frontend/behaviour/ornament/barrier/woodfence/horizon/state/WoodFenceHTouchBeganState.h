//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef WoodFenceHTouchBeganState_h
#define WoodFenceHTouchBeganState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "WoodFenceHBehaviour.h"

// route
#include "BaseRouteSearch.h"

// frame
#include "TimeLine.h"

// asset
#include "AnimatorAsset.h"

class WoodFenceHBehaviour;
class WoodFenceHTouchBeganState : public FiniteState<WoodFenceHBehaviour> {
   public:
    WoodFenceHTouchBeganState();
    virtual ~WoodFenceHTouchBeganState();
    void create(Parameter* parameter);

   private:
    AnimatorAsset* asset;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef CannonTouchBeganState_h
#define CannonTouchBeganState_h

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

// asset
#include "AnimatorAsset.h"

class CannonBehaviour;

class CannonTouchBeganState : public FiniteState<CannonBehaviour> {
   public:
    CannonTouchBeganState();
    virtual ~CannonTouchBeganState();
    void create(Parameter* parameter) override;

   private:
    AnimatorAsset* asset;
};

#endif

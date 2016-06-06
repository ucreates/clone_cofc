//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef MortarTouchBeganState_h
#define MortarTouchBeganState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "MortarBehaviour.h"

// route
#include "BaseRouteSearch.h"

// frame
#include "TimeLine.h"

// asset
#include "AnimatorAsset.h"

class MortarBehaviour;

class MortarTouchBeganState : public FiniteState<MortarBehaviour> {
   public:
    MortarTouchBeganState();
    virtual ~MortarTouchBeganState();
    void create(Parameter* parameter);

   private:
    AnimatorAsset* asset;
};

#endif

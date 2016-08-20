//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GiantLoseState_h
#define GiantLoseState_h
// state
#include "FiniteState.h"
#include "UnitLoseState.h"
// behaviour
#include "GiantBehaviour.h"
// asset
#include "AnimatorAsset.h"
class GiantBehaviour;
class GiantLoseState : public FiniteState<GiantBehaviour>, UnitLoseState<GiantBehaviour> {
   public:
    GiantLoseState();
    virtual ~GiantLoseState();
    void create() override;
};
#endif

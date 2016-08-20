//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarbarianWinState_h
#define BarbarianWinState_h
// state
#include "FiniteState.h"
#include "UnitWinState.h"
// behaviour
#include "BarbarianBehaviour.h"
// asset
#include "AnimatorAsset.h"
class BarbarianBehaviour;
class BarbarianWinState : public FiniteState<BarbarianBehaviour>, UnitWinState<BarbarianBehaviour> {
   public:
    BarbarianWinState();
    virtual ~BarbarianWinState();
    void create() override;
};
#endif

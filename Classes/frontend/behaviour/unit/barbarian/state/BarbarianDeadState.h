//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarbarianDeadState_h
#define BarbarianDeadState_h
// state
#include "FiniteState.h"
#include "UnitDeadState.h"
// behaviour
#include "BarbarianBehaviour.h"
class BarbarianBehaviour;
class BarbarianDeadState : public FiniteState<BarbarianBehaviour>, UnitDeadState<BarbarianBehaviour> {
   public:
    BarbarianDeadState();
    virtual ~BarbarianDeadState();
    void create() override;
};
#endif

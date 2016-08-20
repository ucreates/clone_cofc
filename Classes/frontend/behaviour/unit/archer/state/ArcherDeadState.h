//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ArcherDeadState_h
#define ArcherDeadState_h
// state
#include "FiniteState.h"
#include "UnitDeadState.h"
// behaviour
#include "ArcherBehaviour.h"
class ArcherDeadState;
class ArcherDeadState : public FiniteState<ArcherBehaviour>, UnitDeadState<ArcherBehaviour> {
   public:
    ArcherDeadState();
    virtual ~ArcherDeadState();
    void create() override;
};
#endif

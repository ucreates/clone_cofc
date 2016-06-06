//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ArcherMoveState_h
#define ArcherMoveState_h

// state
#include "FiniteState.h"
#include "UnitMoveState.h"

// behaviour
#include "BaseUnitBehaviour.h"
#include "ArcherBehaviour.h"

class ArcherBehaviour;

class ArcherMoveState : public FiniteState<ArcherBehaviour>, UnitMoveState<ArcherBehaviour> {
   public:
    ArcherMoveState();
    virtual ~ArcherMoveState();
    void create() override;
    void update(float delta) override;
};

#endif

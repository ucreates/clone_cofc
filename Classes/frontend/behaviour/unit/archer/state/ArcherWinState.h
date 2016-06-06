//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ArcherWinState_h
#define ArcherWinState_h

// state
#include "FiniteState.h"
#include "UnitWinState.h"

// behaviour
#include "ArcherBehaviour.h"

// asset
#include "AnimatorAsset.h"

class ArcherBehaviour;

class ArcherWinState : public FiniteState<ArcherBehaviour>, UnitWinState<ArcherBehaviour> {
   public:
    ArcherWinState();
    virtual ~ArcherWinState();
    void create() override;
};

#endif

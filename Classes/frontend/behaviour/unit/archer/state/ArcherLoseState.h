//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ArcherLoseState_h
#define ArcherLoseState_h
// state
#include "FiniteState.h"
#include "UnitLoseState.h"
// behaviour
#include "ArcherBehaviour.h"
// asset
#include "AnimatorAsset.h"
class ArcherBehaviour;
class ArcherLoseState : public FiniteState<ArcherBehaviour>, UnitLoseState<ArcherBehaviour> {
   public:
    ArcherLoseState();
    virtual ~ArcherLoseState();
    void create() override;
};
#endif

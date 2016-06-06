//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattleTransitionState_h
#define BattleTransitionState_h

// layer
#include "BattleLayer.h"

// state
#include "FiniteState.h"
#include "BaseTransitionState.h"

class BattleTransitionState : public FiniteState<BattleLayer>, public BaseTransitionState<BattleLayer> {
   public:
    BattleTransitionState();
    virtual ~BattleTransitionState();
    void create() override;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattleBGMState_h
#define BattleBGMState_h

// layer
#include "BattleLayer.h"

// state
#include "FiniteState.h"

class BattleLayer;

class BattleBGMState : public FiniteState<BattleLayer> {
   public:
    BattleBGMState();
    virtual ~BattleBGMState();
    void create(Parameter* parameter) override;
    void update(float delta = 0.0f) override;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattleFrameState_h
#define BattleFrameState_h

// layer
#include "BattleLayer.h"

// state
#include "FiniteState.h"

class BattleLayer;

class BattleFrameState : public FiniteState<BattleLayer> {
   public:
    BattleFrameState();
    virtual ~BattleFrameState();
    void create() override;
    void update(float delta) override;
};

#endif

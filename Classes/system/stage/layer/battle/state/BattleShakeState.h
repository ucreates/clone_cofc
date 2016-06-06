//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattleShakeState_h
#define BattleShakeState_h

// debug
#include "Macro.h"

// layer
#include "BattleLayer.h"

// physics
#include "Bouncy.h"

// state
#include "FiniteState.h"

class BattleLayer;

class BattleShakeState : public FiniteState<BattleLayer> {
   public:
    BattleShakeState();
    virtual ~BattleShakeState();
    void create() override;
    void update(float delta = 0.0f) override;

   private:
    constexpr static const float SHAKE_SEED = 10.0f;
    static const int REVERSAL_SEED = 10;
    Bouncy bouncy;
    float defaultLayerScale;
};

#endif

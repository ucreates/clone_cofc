//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleDefaultState_h
#define BattleDefaultState_h
// layer
#include "BattleLayer.h"
// state
#include "FiniteState.h"
class BattleLayer;
class BattleDefaultState : public FiniteState<BattleLayer> {
   public:
    BattleDefaultState();
    virtual ~BattleDefaultState();
    void create() override;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleUIResultState_h
#define BattleUIResultState_h
// state
#include "FiniteState.h"
// behaviour
#include "BattleUIBehaviour.h"
class BattleUIBehaviour;
class BattleUIResultState : public FiniteState<BattleUIBehaviour> {
   public:
    BattleUIResultState();
    virtual ~BattleUIResultState();
    void create() override;
   private:
    static const int OVERALL_LEVEL1_PERCENT = 50;
    static const int OVERALL_LEVEL2_PERCENT = 75;
    static const int OVERALL_LEVEL3_PERCENT = 100;
};
#endif

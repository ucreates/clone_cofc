//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleZoomState_h
#define BattleZoomState_h
// layer
#include "BattleLayer.h"
// state
#include "FiniteState.h"
class BattleLayer;
class BattleZoomState : public FiniteState<BattleLayer> {
   public:
    BattleZoomState();
    virtual ~BattleZoomState();
    void create() override;
    void update(float delta) override;
   private:
    constexpr static const float FIRST_FIELD_OF_VIEW = 0.0f;
    constexpr static const float END_FIELD_OF_VIEW = 0.4f;
    constexpr static const float TOTAL_TIME = 2.5f;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BarrierLifeGaugeShowState_h
#define BarrierLifeGaugeShowState_h
// asset
#include "BaseRenderAsset.h"
#include "FiniteState.h"

// behaviour
#include "BarrierLifeGaugeBehaviour.h"

class BarrierLifeGaugeBehaviour;

class BarrierLifeGaugeShowState : public FiniteState<BarrierLifeGaugeBehaviour> {
   public:
    BarrierLifeGaugeShowState();
    virtual ~BarrierLifeGaugeShowState();
    void create() override;
    void update(float delta) override;

   private:
    constexpr static const float CLOSE_TIME = 3.0f;
    BaseRenderAsset* asset;
};

#endif

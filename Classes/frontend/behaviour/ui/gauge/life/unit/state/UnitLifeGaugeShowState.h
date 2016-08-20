//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UnitLifeGaugeShowState_h
#define UnitLifeGaugeShowState_h
// asset
#include "BaseRenderAsset.h"
#include "FiniteState.h"
// behaviour
#include "UnitLifeGaugeBehaviour.h"
class UnitLifeGaugeBehaviour;
class UnitLifeGaugeShowState : public FiniteState<UnitLifeGaugeBehaviour> {
   public:
    UnitLifeGaugeShowState();
    virtual ~UnitLifeGaugeShowState();
    void create() override;
    void update(float delta) override;
   private:
    constexpr static const float CRISIS_PERCENTAGE = 30.0f;
    constexpr static const float CLOSE_TIME = 3.0f;
    BaseRenderAsset* asset;
};
#endif

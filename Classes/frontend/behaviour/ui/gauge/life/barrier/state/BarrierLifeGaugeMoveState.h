//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarrierLifeGaugeMoveState_h
#define BarrierLifeGaugeMoveState_h
// asset
#include "BaseRenderAsset.h"
#include "AnimatorAsset.h"
// state
#include "FiniteState.h"
// behaviour
#include "BarrierLifeGaugeBehaviour.h"
class BarrierLifeGaugeBehaviour;
class BarrierLifeGaugeMoveState : public FiniteState<BarrierLifeGaugeBehaviour> {
   public:
    BarrierLifeGaugeMoveState();
    virtual ~BarrierLifeGaugeMoveState();
    void create() override;
    void update(float delta) override;
   private:
    BaseRenderAsset* unitRenderAsset;
    AnimatorAsset* lifeGuageRenderAsset;
};
#endif

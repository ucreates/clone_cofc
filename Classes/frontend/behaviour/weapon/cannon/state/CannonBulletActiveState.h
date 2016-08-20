//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef CannonBulletActiveState_h
#define CannonBulletActiveState_h
// state
#include "FiniteState.h"
// behaviour
#include "CannonBulletBehaviour.h"
// asset
#include "BaseRenderAsset.h"
#include "LayerRangeValidator.h"
class CannonBulletBehaviour;
class CannonBulletActiveState : public FiniteState<CannonBulletBehaviour> {
   public:
    CannonBulletActiveState();
    virtual ~CannonBulletActiveState();
    void create(Parameter* parameter) override;
    void update(float delta) override;
   private:
    BaseRenderAsset* asset;
    float degree;
    LayerRangeValidator* validator;
};
#endif

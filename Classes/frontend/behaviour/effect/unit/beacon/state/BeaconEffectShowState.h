//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BeaconEffectShowState_h
#define BeaconEffectShowState_h
// asset
#include "BaseRenderAsset.h"
#include "FiniteState.h"
// behaviour
#include "BeaconEffectBehaviour.h"
class BeaconEffectBehaviour;
class BeaconEffectShowState : public FiniteState<BeaconEffectBehaviour> {
   public:
    BeaconEffectShowState();
    virtual ~BeaconEffectShowState();
    void create(Parameter* parameter) override;
   private:
    BaseRenderAsset* asset;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef MortarBulletDestroyState_h
#define MortarBulletDestroyState_h

// state
#include "FiniteState.h"

// behaviour
#include "MortarBulletBehaviour.h"

// asset
#include "BaseRenderAsset.h"

class MortarBulletBehaviour;
class MortarBulletDestroyState : public FiniteState<MortarBulletBehaviour> {
   public:
    MortarBulletDestroyState();
    virtual ~MortarBulletDestroyState();
    void create() override;
};

#endif

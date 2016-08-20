//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef CannonBulletDestroyState_h
#define CannonBulletDestroyState_h
// state
#include "FiniteState.h"
// behaviour
#include "CannonBulletBehaviour.h"
class CannonBulletBehaviour;
class CannonBulletDestroyState : public FiniteState<CannonBulletBehaviour> {
   public:
    CannonBulletDestroyState();
    virtual ~CannonBulletDestroyState();
    void create() override;
};
#endif

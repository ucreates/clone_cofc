//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ElixirTankDamageEffectBehaviour_h
#define ElixirTankDamageEffectBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseBehaviour.h"
class ElixirTankDamageEffectBehaviour : public BaseBehaviour {
   public:
    ElixirTankDamageEffectBehaviour();
    virtual ~ElixirTankDamageEffectBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
};
#endif

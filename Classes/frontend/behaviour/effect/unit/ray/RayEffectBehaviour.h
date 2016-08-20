//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef RayEffectBehaviour_h
#define RayEffectBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseBehaviour.h"
class RayEffectBehaviour : public BaseBehaviour {
   public:
    RayEffectBehaviour();
    virtual ~RayEffectBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
};
#endif

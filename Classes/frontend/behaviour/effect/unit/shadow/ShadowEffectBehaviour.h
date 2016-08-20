//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ShadowEffectBehaviour_h
#define ShadowEffectBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseBehaviour.h"
class ShadowEffectBehaviour : public BaseBehaviour {
   public:
    ShadowEffectBehaviour(BaseBehaviour* owner);
    virtual ~ShadowEffectBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position, cocos2d::Size scale) override;
    void onUpdate(float delta = 0.0f) override;
   private:
    BaseBehaviour* unit;
};
#endif

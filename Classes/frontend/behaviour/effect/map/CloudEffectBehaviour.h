//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef CloudEffectBehaviour_h
#define CloudEffectBehaviour_h

// cocos2d
#include "cocos2d.h"

// behaviour
#include "BaseBehaviour.h"
#include "TimeLine.h"

class CloudEffectBehaviour : public BaseBehaviour {
   public:
    CloudEffectBehaviour();
    virtual ~CloudEffectBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onUpdate(float delta = 0.0f) override;

   private:
    TimeLine* frame;
    bool complete;
};

#endif

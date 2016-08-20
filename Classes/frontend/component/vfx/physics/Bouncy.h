//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "cocos2d.h"
#include "Macro.h"
#include "Random.h"
#ifndef Bouncy_h
#define Bouncy_h
class Bouncy {
   public:
    Bouncy();
    Bouncy(float verocity);
    void initialize();
    void setVerocity(float verocity);
    float execute();
   private:
    constexpr static const float MIN_VEROCITY_RATE = 0.05f;
    float e;
    float verocity;
    float originVerocity;
    float seedVerocity;
    float gravity;
};
#endif
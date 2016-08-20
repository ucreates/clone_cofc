//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Slope_h
#define Slope_h
// cocos2d
#include "cocos2d.h"
class Slope {
   public:
    float degree;
    float radian;
    cocos2d::Vec2 trigonomic;
    inline Slope() : Slope(0.0f) {}
    inline Slope(float degree) {
        this->degree = degree;
        this->radian = CC_DEGREES_TO_RADIANS(this->degree);
        float sin = sinf(this->radian);
        float cos = cosf(this->radian);
        this->trigonomic = cocos2d::Vec2(cos, sin);
    }
};
#endif

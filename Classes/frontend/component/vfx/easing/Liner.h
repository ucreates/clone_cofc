//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Liner_h
#define Liner_h
// cocos2d
#include "cocos2d.h"
// entity
#include "Transform.h"
// geography
#include "GeographicNode.h"
class Liner {
   public:
    static float easeIn(float currentTime, float start, float end, float totalTime);
    static float easeOut(float currentTime, float start, float end, float totalTime);
    static float easeInOut(float currentTime, float start, float end, float totalTime);
};
#endif

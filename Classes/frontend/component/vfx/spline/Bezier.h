//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Bezier_h
#define Bezier_h

#include "cocos2d.h"
#include "Macro.h"

class Bezier {
   public:
    static cocos2d::Vec2 create(float currentTime, float totalTime, cocos2d::Vec2 start, cocos2d::Vec2 contol, cocos2d::Vec2 end);
    static cocos2d::Vec2 create(float currentTime, float totalTime, cocos2d::Vec2 start, cocos2d::Vec2 contol1, cocos2d::Vec2 contol2, cocos2d::Vec2 end);
};

#endif

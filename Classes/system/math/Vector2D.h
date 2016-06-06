//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Vector2D_h
#define Vector2D_h

// cocos2d
#include "cocos2d.h"

class Vector2D {
   public:
    static float product(float startDegree, float endDegree);
    static float product(cocos2d::Vec2 start, cocos2d::Vec2 goal);
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Degree_h
#define Degree_h

// cocos2d
#include "cocos2d.h"

// entity
#include "Position.h"

class Degree {
   public:
    static float create(cocos2d::Vec2 start, cocos2d::Vec2 goal, bool plus = false);
    static float create(Position start, Position goal, bool plus = false);
};

#endif

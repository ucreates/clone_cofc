//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Move_h
#define Move_h

// cocos2d
#include "cocos2d.h"

// entity
#include "Transform.h"

// geography
#include "GeographicNode.h"

class Move {
   public:
    static Position execute(Position start, Position goal, float speed = 1.0f);
    static cocos2d::Vec2 execute(cocos2d::Vec2 start, cocos2d::Vec2 goal, float speed = 1.0f);
    static cocos2d::Vec2 execute(cocos2d::Vec2 position, float degree, float speed = 1.0f);
};

#endif

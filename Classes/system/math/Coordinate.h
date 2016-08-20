//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Coordinate_h
#define Coordinate_h
// cocos2d
#include "cocos2d.h"
// entity
#include "Address.h"
#include "Position.h"
class Coordinate {
   public:
    static Address getMiddlePoint(Address start, Address goal);
    static Position getMiddlePoint(Position start, Position goal);
    static cocos2d::Vec2 getMiddlePoint(cocos2d::Vec2 start, cocos2d::Vec2 goal);
    static cocos2d::Vec2 getBetweenPoint(cocos2d::Vec2 start, cocos2d::Vec2 goal, float percentage);
};
#endif

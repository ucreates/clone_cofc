//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Position_h
#define Position_h
// cocos2d
#include "cocos2d.h"
class Position {
   public:
    float x;
    float y;
    int zorder;
    cocos2d::Vec2 vector2d;
    inline Position() : Position(cocos2d::Vec2::ZERO, 0) {}
    inline Position(cocos2d::Vec2 position, int zorder) {
        this->x = position.x;
        this->y = position.y;
        this->zorder = zorder;
        this->vector2d = position;
    }
    inline void add(cocos2d::Vec2 position, int zorder = 0) {
        this->x += position.x;
        this->y += position.y;
        this->zorder += zorder;
        this->vector2d += position;
    }
    inline void add(int zorder) { this->zorder += zorder; }
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// math
#include "Trigonomic.h"
using namespace cocos2d;
Vec2 Trigonomic::create(Vec2 start, Vec2 goal) {
    Point trigonomic = Point(0, 0);
    Vec2 diff = goal - start;
    float radian = atan2(diff.y, diff.x);
    trigonomic = Point(cos(radian), sin(radian));
    return trigonomic;
}

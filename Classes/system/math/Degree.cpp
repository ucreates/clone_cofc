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
#include "Degree.h"
#include "Radian.h"
using namespace cocos2d;
float Degree::create(Vec2 start, Vec2 goal, bool plus) {
    float radian = Radian::create(start, goal);
    float degree = CC_RADIANS_TO_DEGREES(radian);
    if (plus && 0.0f > degree) {
        degree = 360.0f + degree;
    }
    return degree;
}
float Degree::create(Position start, Position goal, bool plus) {
    float radian = Radian::create(start, goal);
    float degree = CC_RADIANS_TO_DEGREES(radian);
    if (plus && 0.0f > degree) {
        degree = 360.0f + degree;
    }
    return degree;
}

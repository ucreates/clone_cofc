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
#include "Vector2D.h"

using namespace cocos2d;

float Vector2D::product(float startDegree, float endDegree) {
    float sdr = CC_DEGREES_TO_RADIANS(startDegree);
    float edr = CC_DEGREES_TO_RADIANS(endDegree);
    float sdrx = cosf(sdr);
    float sdry = sinf(sdr);
    float edrx = cosf(edr);
    float edry = sinf(edr);
    float product = sdrx * edry - sdry * edrx;
    return product;
}

float Vector2D::product(Vec2 start, Vec2 goal) { return start.x * goal.y - goal.x + start.y; }
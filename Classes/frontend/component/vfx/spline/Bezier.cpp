//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "Bezier.h"
using namespace cocos2d;

Vec2 Bezier::create(float currentTime, float totalTime, Vec2 start, Vec2 contol, Vec2 end) {
    float t = (currentTime / totalTime);
    if (t > 1.0f) {
        t = 1.0f;
    }

    float tp = 1.0f - t;
    if (tp < 0.0f) {
        tp = 0.0f;
    }

    float x = t * t * end.x + 2 * t * tp * contol.x + tp * tp * start.x;
    float y = t * t * end.y + 2 * t * tp * contol.y + tp * tp * start.y;
    return Vec2(x, y);
}

Vec2 Bezier::create(float currentTime, float totalTime, Vec2 start, Vec2 contol1, Vec2 contol2, Vec2 end) {
    float t = (currentTime / totalTime);
    if (t > 1.0f) {
        t = 1.0f;
    }

    float tp = 1.0f - t;
    if (tp < 0.0f) {
        tp = 0.0f;
    }

    float x = t * t * t * end.x + 3 * t * t * tp * contol2.x + 3 * t * tp * tp * contol1.x + tp * tp * tp * start.x;
    float y = t * t * t * end.y + 3 * t * t * tp * contol2.y + 3 * t * tp * tp * contol1.y + tp * tp * tp * start.y;
    return Vec2(x, y);
}

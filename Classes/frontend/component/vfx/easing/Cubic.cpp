//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include <math.h>
#include "Cubic.h"

float Cubic::easeIn(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    float diff = end - start;
    return diff * powf(rate, 3) + start;
}

float Cubic::easeOut(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    rate -= 1.0f;
    float diff = end - start;
    return diff * (powf(rate, 3) + 1) + start;
}

float Cubic::easeInOut(float currentTime, float start, float end, float totalTime) {
    bool switchType = currentTime / totalTime >= 0.5f;
    if (false == switchType) {
        return Cubic::easeIn(currentTime, start, end, totalTime);
    } else {
        return Cubic::easeOut(currentTime, start, end, totalTime);
    }
}

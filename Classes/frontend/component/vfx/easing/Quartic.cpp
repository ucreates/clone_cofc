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
#include "Quartic.h"

float Quartic::easeIn(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    float diff = end - start;
    return diff * powf(rate, 4) + start;
}

float Quartic::easeOut(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    rate -= 1.0f;
    float diff = end - start;
    return -1.0f * diff * (powf(rate, 4) - 1) + start;
}

float Quartic::easeInOut(float currentTime, float start, float end, float totalTime) {
    bool switchType = currentTime / totalTime >= 0.5f;
    if (false == switchType) {
        return Quartic::easeIn(currentTime, start, end, totalTime);
    } else {
        return Quartic::easeOut(currentTime, start, end, totalTime);
    }
}

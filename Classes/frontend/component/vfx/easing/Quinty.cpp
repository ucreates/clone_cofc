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
#include "Quinty.h"

float Quinty::easeIn(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    float diff = end - start;
    return diff * powf(rate, 5) + start;
}

float Quinty::easeOut(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    rate -= 1.0f;
    float diff = end - start;
    return -1.0f * diff * (powf(rate, 5) - 1) + start;
}

float Quinty::easeInOut(float currentTime, float start, float end, float totalTime) {
    bool switchType = currentTime / totalTime >= 0.5f;
    if (false == switchType) {
        return Quinty::easeIn(currentTime, start, end, totalTime);
    } else {
        return Quinty::easeOut(currentTime, start, end, totalTime);
    }
}

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
#include "Exponential.h"

float Exponential::easeIn(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    float diff = end - start;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    return diff * powf(2, 10.0f * (rate - 1.0f)) + start;
}

float Exponential::easeOut(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    float diff = end - start;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    return diff * (-1.0f * powf(2.0f, -10.0f * rate) + 1.0f) + start;
}

float Exponential::easeInOut(float currentTime, float start, float end, float totalTime) {
    bool switchType = currentTime / totalTime >= 0.5f;
    if (false == switchType) {
        return Exponential::easeIn(currentTime, start, end, totalTime);
    } else {
        return Exponential::easeOut(currentTime, start, end, totalTime);
    }
}

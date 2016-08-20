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
#include "Quadratic.h"
float Quadratic::easeIn(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    float diff = end - start;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    return diff * powf(rate, 2) + start;
}
float Quadratic::easeOut(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    float diff = end - start;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    return -1.0f * diff * rate * (diff - 2) + start;
}
float Quadratic::easeInOut(float currentTime, float start, float end, float totalTime) {
    bool switchType = currentTime / totalTime >= 0.5f;
    if (false == switchType) {
        return Quadratic::easeIn(currentTime, start, end, totalTime);
    } else {
        return Quadratic::easeOut(currentTime, start, end, totalTime);
    }
}

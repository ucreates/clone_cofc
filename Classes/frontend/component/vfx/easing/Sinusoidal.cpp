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
#include "Sinusoidal.h"
float Sinusoidal::easeIn(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    float diff = end - start;
    return -1.0f * diff * cosf(rate * (M_PI * 0.5f)) + diff + start;
}
float Sinusoidal::easeOut(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    float diff = end - start;
    return diff * sinf(rate * (M_PI * 0.5f)) + start;
}
float Sinusoidal::easeInOut(float currentTime, float start, float end, float totalTime) {
    bool switchType = currentTime / totalTime >= 0.5f;
    if (false == switchType) {
        return Sinusoidal::easeIn(currentTime, start, end, totalTime);
    } else {
        return Sinusoidal::easeOut(currentTime, start, end, totalTime);
    }
}

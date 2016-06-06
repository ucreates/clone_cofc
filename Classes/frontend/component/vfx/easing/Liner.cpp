//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "Liner.h"

float Liner::easeIn(float currentTime, float start, float end, float totalTime) {
    float rate = currentTime / totalTime;
    float diff = end - start;
    if (1.0f <= rate) {
        rate = 1.0f;
    }
    return diff * rate + start;
}

float Liner::easeOut(float currentTime, float start, float end, float totalTime) {
    float rate = 1.0f - (currentTime / totalTime);
    float diff = end - start;
    if (0.0f >= rate) {
        rate = 0.0f;
    }
    return diff * rate + start;
}

float Liner::easeInOut(float currentTime, float start, float end, float totalTime) {
    bool switchType = currentTime / totalTime >= 0.5f;
    if (false == switchType) {
        return Liner::easeIn(currentTime, start, end, totalTime);
    } else {
        return Liner::easeOut(currentTime, start, end, totalTime);
    }
}

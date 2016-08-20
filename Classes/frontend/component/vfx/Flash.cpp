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
#include "Flash.h"
#include "Alpha.h"
float Flash::execute(float time) {
    float flash = sinf(time) * Alpha::NOT_ALPHA;
    if (0 > flash) {
        flash *= -1.0f;
    }
    return flash;
}
float Flash::execute(float time, float basePercentage) {
    float flashRate = Alpha::NOT_ALPHA * basePercentage * 0.01f;
    float restRate = Alpha::NOT_ALPHA - flashRate;
    float flash = sinf(time) * restRate;
    if (0 > flash) {
        flash *= -1.0f;
    }
    flash += flashRate;
    return flash;
}
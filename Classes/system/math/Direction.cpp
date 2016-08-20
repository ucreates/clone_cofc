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
#include "Direction.h"
Direction::DIRECT Direction::getDirection(float degree) {
    if (0 <= degree && degree < 35) {
        return DIRECT::HORIZON_RIGHT;
    } else if (-35 <= degree && degree < 0) {
        return DIRECT::HORIZON_RIGHT;
    } else if (135 <= degree && degree <= 180) {
        return DIRECT::HORIZON_LEFT;
    } else if (-180 <= degree && degree < -135) {
        return DIRECT::HORIZON_LEFT;
    } else if (35 <= degree && degree < 90) {
        return DIRECT::UPPER_RIGHT;
    } else if (90 <= degree && degree < 135) {
        return DIRECT::UPPER_LEFT;
    } else if (-90 <= degree && degree < -35) {
        return DIRECT::UNDER_RIGHT;
    } else if (-135 <= degree && degree < -90) {
        return DIRECT::UNDER_LEFT;
    }
    return DIRECT::UNKNOWN;
}
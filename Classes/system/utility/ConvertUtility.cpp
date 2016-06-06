//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// utility
#include "ConvertUtility.h"

using namespace cocos2d;

Vec2 ConvertUtility::toVec2(Size size) { return Vec2(size.width, size.height); }

std::string ConvertUtility::toString(int val) {
    std::ostringstream ts;
    ts << val;
    return ts.str();
}

std::string ConvertUtility::toString(float val) {
    std::ostringstream ts;
    ts << val;
    return ts.str();
}

std::string ConvertUtility::toString(clock_t val) {
    std::ostringstream ts;
    ts << val;
    return ts.str();
}

int ConvertUtility::toInt(std::string val) {
    std::stringstream ss(val);
    int ret = 0;
    ss >> ret;
    return ret;
}

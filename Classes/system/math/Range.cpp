//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// device
#include "Screen.h"
// math
#include "Range.h"
using namespace cocos2d;
Rect Range::getLayerRange(float layerScale, bool fullScreen) {
    Size size;
    if (false != fullScreen) {
        size = Screen::getFullScreenSize(layerScale);
    } else {
        size = Screen::getHalfScreenSize(layerScale);
    }
    Rect rect(-1.0f * size.width, -1.0 * size.height, size.width * 2.0f, size.height * 2.0f);
    return rect;
}
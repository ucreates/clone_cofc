//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Range_h
#define Range_h

// cocos2d
#include "cocos2d.h"

class Range {
   public:
    static cocos2d::Rect getLayerRange(float layerScale, bool fullScreen = true);
};

#endif

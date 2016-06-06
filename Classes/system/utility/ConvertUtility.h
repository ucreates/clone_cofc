//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Convert_h
#define Convert_h

// standard
#include <time.h>

// cocos2d
#include "cocos2d.h"

class ConvertUtility {
   public:
    static cocos2d::Vec2 toVec2(cocos2d::Size size);
    static std::string toString(int val);
    static std::string toString(float val);
    static std::string toString(clock_t val);
    static int toInt(std::string val);
};

#endif

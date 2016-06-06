//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Scale_h
#define Scale_h

// cocos2d
#include "cocos2d.h"

class Scale {
   public:
    Scale();
    Scale(cocos2d::Size scale);
    ~Scale();
    cocos2d::Size getAllScale();
    cocos2d::Size getHalfScale();
    void update(cocos2d::Size scale);

   private:
    cocos2d::Size scale;
    cocos2d::Size halfScale;
};

#endif

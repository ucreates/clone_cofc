//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Screen_h
#define Screen_h
// cocos2d
#include "cocos2d.h"
// entity
#include "Position.h"
class Screen {
   public:
    static cocos2d::Size getFullScreenSize(float scale = 1.0f);
    static cocos2d::Size getHalfScreenSize(float scale = 1.0f);
    static cocos2d::Size getNodeScaleByScreenSize(cocos2d::Node* node, bool dump = false);
    static Position getCenterPosition(int zorder = 0);
    static Position getEdgePosition(int zorder = 0);
    static Position getScreenRect(float scale = 1.0f);
};
#endif

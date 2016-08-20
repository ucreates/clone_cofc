//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// cocos2d
#include "cocos2d.h"
// debug
#include "Macro.h"
// geographic
#include "GeographicNode.h"
#ifndef GeographicUtility_h
#define GeographicUtility_h
class GeographicUtility {
   public:
    static void drawDepth(cocos2d::Layer* layer, GeographicNode* node);
    static void drawDot(cocos2d::Layer* layer, cocos2d::Vec2 position);
   private:
    static const int DRAW_DEPTH = 2000;
    static const int DRAW_DOT_DEPTH = 4000;
};
#endif
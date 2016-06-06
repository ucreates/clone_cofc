//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GeographicSlope_h
#define GeographicSlope_h

#include "cocos2d.h"
#include "Slope.h"

class GeographicSlope {
   public:
    //マップ(1ユニット単位)の1辺の角度:36.9
    Slope column;
    Slope row;
    GeographicSlope();
    GeographicSlope(float coldegree, float rowdegree);
    void update(float coldegree, float rowdegree);
};

#endif

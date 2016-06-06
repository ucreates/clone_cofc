//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GeographicDepth_h
#define GeographicDepth_h

class GeographicDepth {
   public:
    static const int UI_DEPTH = 100000;
    static const int UNIT_DEPTH = 0;
    static const int ORNAMENT_TOUCH_DEPTH = 10000;
    static const int DUMMY_NODE_DEPTH = 1;
    static const int BACKGROUND_DEPTH = 0;
    static const int UNIT_DEPTH_RELATIVE_TO_NODE = 2;
    static const int WEAPON_DEPTH_RELATIVE_TO_NODE = 500;
    static const int BARRIER_DEPTH_RELATIVE_TO_NODE = -50;
    static const int EFFECT_DEPTH_RELATIVE_TO_NODE = 1000;
    static int create(int x, int y, int z, int diffHeightX, int diffHeightY);
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Direction_h
#define Direction_h
class Direction {
   public:
    enum DIRECT {
        UNDER_RIGHT = 0x00,
        UNDER_LEFT = 0x01,
        HORIZON_RIGHT = 0x02,
        HORIZON_LEFT = 0x03,
        UPPER_RIGHT = 0x04,
        UPPER_LEFT = 0x05,
        UNKNOWN = 0x06,
    };
    static DIRECT getDirection(float degree);
};
#endif

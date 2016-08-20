//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TimeLine_h
#define TimeLine_h
#include "cocos2d.h"
#include "Macro.h"
class TimeLine {
   public:
    TimeLine();
    int getFrame();
    float getFrameTime();
    void setFrame(int frame);
    void setFrameTime(float delta);
    void update(float delta, int frame = 1);
    void reset();
    void reset(int frame, float frameTime);
   private:
    float frameTime;
    int frame;
};
#endif

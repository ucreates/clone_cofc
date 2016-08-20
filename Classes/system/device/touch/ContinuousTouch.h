//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ContinuousTouch_h
#define ContinuousTouch_h
// stl
#include <vector>
// cocos2d
#include "cocos2d.h"
// device
#include "BaseTouch.h"
// vfx
#include "TimeLine.h"
class ContinuousTouch : public BaseTouch {
   public:
    ContinuousTouch();
    ContinuousTouch(cocos2d::Layer* layer);
    virtual ~ContinuousTouch();
    void onBegan(std::vector<cocos2d::Point> touchPointVector) override;
    void onMove(std::vector<cocos2d::Point> touchPointVector) override;
    void onEnd(std::vector<cocos2d::Point> touchPointVector) override;
    void onExecute() override;
   private:
    static const int ENABLE_TOUCH_THRESHOLD_FRAME = 10;
    TimeLine* timeLine;
};
#endif
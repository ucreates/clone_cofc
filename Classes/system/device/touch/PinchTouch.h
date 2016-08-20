//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef PinchTouch_h
#define PinchTouch_h
// stl
#include <vector>
// cocos2d
#include "cocos2d.h"
// touch
#include "BaseTouch.h"
class PinchTouch : public BaseTouch {
   public:
    PinchTouch();
    PinchTouch(cocos2d::Layer* layer, float defaultLayerScale);
    virtual ~PinchTouch();
    void onBegan(std::vector<cocos2d::Point> touchPointVector) override;
    void onMove(std::vector<cocos2d::Point> touchPointVector) override;
    void onExecute() override;
   private:
    constexpr static const float MIN_DISTANCE = 1.0f;
    constexpr static const float MIN_SCALE_RATE = 0.6f;
    constexpr static const float MAX_SCALE_RATE = 2.0f;
    float defaultDistance;
    float pinchRate;
};
#endif
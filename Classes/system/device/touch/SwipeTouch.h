//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef SwipeTouch_h
#define SwipeTouch_h

// stl
#include <vector>

// cocos2d
#include "cocos2d.h"

// touch
#include "BaseTouch.h"

class SwipeTouch : public BaseTouch {
   public:
    SwipeTouch();
    SwipeTouch(cocos2d::Layer* layer, float defaultLayerScale);
    virtual ~SwipeTouch();
    void onBegan(std::vector<cocos2d::Point> touchPointVector) override;
    void onMove(std::vector<cocos2d::Point> touchPointVector) override;
    void onEnd(std::vector<cocos2d::Point> touchPointVector) override;
    void onExecute() override;

   private:
    constexpr static const float POWER_FRICTION = 0.1f;
    constexpr static const float SPEED_FRICTION = 0.9f;
    static const long MAX_MOVE_POINT_LIST = 2;
    cocos2d::Vec2 direction;
    float swipePower;
    float defaultLayerScale;
};

#endif
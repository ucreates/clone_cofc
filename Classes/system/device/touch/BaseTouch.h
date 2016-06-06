//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseTouch_h
#define BaseTouch_h

// cocos2d
#include "cocos2d.h"

// stl
#include <vector>

class BaseTouch {
   public:
    static const int SINGLE_TOUCH_COUNT = 1;
    static const int DOUBLE_TOUCH_COUNT = 2;
    BaseTouch();
    virtual ~BaseTouch();
    virtual void onBegan(std::vector<cocos2d::Point> touchPointVector);
    virtual void onMove(std::vector<cocos2d::Point> touchPointVector);
    virtual void onEnd(std::vector<cocos2d::Point> touchPointVector);
    virtual void onExecute();
    bool getEnableTouch();
    void setEnableTouch(bool enable);
    cocos2d::Touch* getPreviousTouch();
    void setPreviousTouch(cocos2d::Touch* touch);

   protected:
    cocos2d::Point beganPoint;
    cocos2d::Point endPoint;
    cocos2d::Layer* parentLayer;
    cocos2d::Touch* previousTouch;
    std::vector<cocos2d::Point> movePointVector;
    float defaultLayerScale;
    bool enable;
    bool firstTouch;
    void adjustLayer();
};

#endif
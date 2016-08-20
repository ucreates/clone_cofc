//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// touch
#include "PinchTouch.h"
// math
#include "Distance.h"
using namespace cocos2d;
PinchTouch::PinchTouch() : PinchTouch(NULL, 0.0f) {}
PinchTouch::PinchTouch(cocos2d::Layer* layer, float defaultLayerScale) {
    this->enable = false;
    this->defaultDistance = 0.0f;
    this->pinchRate = PinchTouch::MIN_SCALE_RATE;
    this->defaultLayerScale = defaultLayerScale;
    this->parentLayer = layer;
}
PinchTouch::~PinchTouch() {}
void PinchTouch::onBegan(std::vector<Point> touchPointVector) {
    if (false == this->enable || BaseTouch::DOUBLE_TOUCH_COUNT != touchPointVector.size()) {
        return;
    }
    Point firstTouchPoint = touchPointVector.at(0);
    Point secondTouchPoint = touchPointVector.at(1);
    this->defaultDistance = Distance::create(firstTouchPoint, secondTouchPoint);
    if (PinchTouch::MIN_DISTANCE > this->defaultDistance) {
        this->defaultDistance = PinchTouch::MIN_DISTANCE;
    }
}
void PinchTouch::onMove(std::vector<Point> touchPointVector) {
    if (false == this->enable || BaseTouch::DOUBLE_TOUCH_COUNT != touchPointVector.size() || NULL == this->previousTouch) {
        return;
    }
    Point firstTouchPoint = touchPointVector.at(0);
    Point secondTouchPoint = touchPointVector.at(1);
    float movePointDistance = Distance::create(firstTouchPoint, secondTouchPoint);
    float rate = movePointDistance / this->defaultDistance;
    this->pinchRate *= rate;
    if (this->pinchRate <= PinchTouch::MIN_SCALE_RATE) {
        this->pinchRate = PinchTouch::MIN_SCALE_RATE;
    }
    if (this->pinchRate >= PinchTouch::MAX_SCALE_RATE) {
        this->pinchRate = PinchTouch::MAX_SCALE_RATE;
    }
}
void PinchTouch::onExecute() {
    if (false == this->enable) {
        return;
    }
    this->parentLayer->setScale(this->pinchRate);
    this->adjustLayer();
}

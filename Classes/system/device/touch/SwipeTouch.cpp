//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// device
#include "SwipeTouch.h"
// math
#include "Trigonomic.h"
#include "Distance.h"
using namespace cocos2d;
SwipeTouch::SwipeTouch() : SwipeTouch(NULL, 0.0f) {}
SwipeTouch::SwipeTouch(cocos2d::Layer* layer, float defaultLayerScale) {
    this->enable = false;
    this->endPoint = Point(0.0f, 0.0f);
    this->defaultLayerScale = defaultLayerScale;
    this->parentLayer = layer;
}
SwipeTouch::~SwipeTouch() {}
void SwipeTouch::onBegan(std::vector<Point> touchPointVector) {
    if (BaseTouch::SINGLE_TOUCH_COUNT != touchPointVector.size() || false == this->enable) {
        return;
    }
    this->beganPoint = touchPointVector.at(0);
}
void SwipeTouch::onMove(std::vector<Point> touchPointVector) {
    if (BaseTouch::SINGLE_TOUCH_COUNT != touchPointVector.size() || false == this->enable) {
        return;
    }
    Vec2 cpos = touchPointVector.at(0);
    Vec2 ppos;
    if (0 == this->movePointVector.size()) {
        ppos = this->beganPoint;
    } else {
        long index = this->movePointVector.size() - 1;
        ppos = this->movePointVector.at(index);
    }
    Vec2 diff = cpos - ppos;
    Vec2 npos = diff + this->parentLayer->getPosition();
    this->parentLayer->setPosition(npos);
    this->movePointVector.push_back(cpos);
    return;
}
void SwipeTouch::onEnd(std::vector<Point> touchPointVector) {
    if (BaseTouch::SINGLE_TOUCH_COUNT != touchPointVector.size() || false == this->enable) {
        return;
    }
    if (SwipeTouch::MAX_MOVE_POINT_LIST < movePointVector.size()) {
        long index = this->movePointVector.size() - SwipeTouch::MAX_MOVE_POINT_LIST;
        Vec2 lmpos = this->movePointVector.at(index);
        this->endPoint = touchPointVector.at(0);
        this->swipePower = Distance::create(lmpos, this->endPoint) * SwipeTouch::POWER_FRICTION;
        this->direction = Trigonomic::create(lmpos, this->endPoint);
    } else {
        this->swipePower = 0.0f;
        this->direction = Vec2(0.0f, 0.0f);
    }
    movePointVector.clear();
}
void SwipeTouch::onExecute() {
    if (false == this->enable) {
        return;
    }
    Vec2 cp = this->parentLayer->getPosition();
    float sx = this->swipePower * this->direction.x;
    float sy = this->swipePower * this->direction.y;
    this->swipePower *= SwipeTouch::SPEED_FRICTION;
    Vec2 swipe = Vec2(sx, sy);
    cp += swipe;
    this->parentLayer->setPosition(cp);
    this->adjustLayer();
}
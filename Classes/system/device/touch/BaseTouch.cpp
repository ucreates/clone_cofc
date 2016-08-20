//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// debug
#include "Macro.h"
// device
#include "BaseTouch.h"
// layer
#include "BattleLayer.h"
// math
#include "Range.h"
using namespace cocos2d;
BaseTouch::BaseTouch() {
    this->firstTouch = true;
    this->enable = true;
    this->previousTouch = NULL;
}
BaseTouch::~BaseTouch() {}
void BaseTouch::onBegan(std::vector<Point> touchPointVector) { return; }
void BaseTouch::onMove(std::vector<Point> touchPointVector) { return; }
void BaseTouch::onEnd(std::vector<Point> touchPointVector) { return; }
void BaseTouch::onExecute() { return; }
bool BaseTouch::getEnableTouch() { return this->enable; }
void BaseTouch::setEnableTouch(bool enable) { this->enable = enable; }
cocos2d::Touch* BaseTouch::getPreviousTouch() { return this->previousTouch; }
void BaseTouch::setPreviousTouch(cocos2d::Touch* touch) {
    if (NULL != this->previousTouch) {
        CC_SAFE_DELETE(this->previousTouch);
    }
    if (NULL != touch) {
        this->previousTouch = new Touch(*touch);
    }
}
void BaseTouch::adjustLayer() {
    float scaleRate = this->parentLayer->getScale();
    scaleRate = scaleRate - BattleLayer::DEFAULT_SWIPE_SCALE_RATE;
    if (scaleRate < 0.0f) {
        scaleRate = 0.0f;
    }
    Rect range = Range::getLayerRange(scaleRate, false);
    float hlimx = range.getMaxX();
    float hlimy = range.getMaxY();
    float ulimx = range.getMinX();
    float ulimy = range.getMinY();
    Vec2 cp = this->parentLayer->getPosition();
    if (cp.x <= ulimx) {
        cp = Vec2(ulimx, cp.y);
    } else if (hlimx <= cp.x) {
        cp = Vec2(hlimx, cp.y);
    }
    if (cp.y <= ulimy) {
        cp = Vec2(cp.x, ulimy);
    } else if (hlimy <= cp.y) {
        cp = Vec2(cp.x, hlimy);
    }
    this->parentLayer->setPosition(cp);
}
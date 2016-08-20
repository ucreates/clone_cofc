//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "ArrowActiveBezier3DState.h"
// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
#include "GeographicDepth.h"
#include "GeographicUtility.h"
// utility
#include "Degree.h"
#include "Distance.h"
#include "Coordinate.h"
// vfx
#include "Bezier.h"
using namespace cocos2d;
ArrowActiveBezier3DState::ArrowActiveBezier3DState() {}
ArrowActiveBezier3DState::~ArrowActiveBezier3DState() {}
void ArrowActiveBezier3DState::create() {
    if (NULL == this->owner->goal) {
        return;
    }
    this->frame->reset();
    this->asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    this->asset->transform(this->owner->start->depth + GeographicDepth::WEAPON_DEPTH_RELATIVE_TO_NODE);
    this->start = this->owner->start->position + Vec2(0.0f, this->owner->paddingHeight);
    this->position = this->start;
    Vec2 controlPoint1 = Coordinate::getBetweenPoint(this->position, this->owner->goal->position, 0.33f);
    Vec2 controlPoint2 = Coordinate::getBetweenPoint(this->position, this->owner->goal->position, 0.66f);
    float distance = Distance::create(this->position, this->owner->goal->position);
    float power = distance * ArrowActiveBezier3DState::HEIGHT_RATE;
    this->control1 = controlPoint1 + Vec2(0, power);
    this->control2 = controlPoint2 + Vec2(0, power);
    if (false != this->owner->debug) {
        Layer* layer = this->owner->getLayer();
        GeographicUtility::drawDot(layer, this->control1);
        GeographicUtility::drawDot(layer, this->control2);
    }
    this->moveTime = distance / ArrowActiveBezier3DState::MOVE_SPEED;
    this->asset->show();
    return;
}
void ArrowActiveBezier3DState::update(float delta) {
    float currentTime = this->frame->getFrameTime();
    if (NULL == this->owner->goal) {
        this->owner->getStateMachine()->change("destroy");
        return;
    }
    Vec2 position = Bezier::create(currentTime, this->moveTime, this->start, this->control1, this->control2, this->owner->goal->position);
    if (position == this->owner->goal->position) {
        this->owner->getStateMachine()->change("destroy");
        return;
    }
    this->asset->transform(position);
    float degree = (Degree::create(this->position, position) + ArrowActiveBezier3DState::DEFAULT_DEGREE) * -1;
    this->asset->transform(degree);
    this->position = position;
    if (false != this->owner->debug) {
        Layer* layer = this->owner->getLayer();
        GeographicUtility::drawDot(layer, position);
    }
    this->frame->setFrameTime(delta);
    return;
}
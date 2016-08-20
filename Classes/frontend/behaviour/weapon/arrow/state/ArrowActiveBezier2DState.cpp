//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "ArrowActiveBezier2DState.h"
// const
#include "Macro.h"
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
ArrowActiveBezier2DState::ArrowActiveBezier2DState() {}
ArrowActiveBezier2DState::~ArrowActiveBezier2DState() {}
void ArrowActiveBezier2DState::create() {
    this->frame->reset();
    this->asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    this->asset->transform(this->owner->start->depth + GeographicDepth::WEAPON_DEPTH_RELATIVE_TO_NODE);
    this->position = this->owner->start->position;
    Vec2 middlePoint = Coordinate::getMiddlePoint(this->owner->start->position, this->owner->goal->position);
    float distance = Distance::create(this->owner->start->position, this->owner->goal->position);
    float power = distance * ArrowActiveBezier2DState::HEIGHT_RATE;
    this->control = middlePoint + Vec2(0, power);
    if (false != this->owner->debug) {
        Layer* layer = this->owner->getLayer();
        GeographicUtility::drawDot(layer, this->control);
    }
    this->moveTime = distance / ArrowActiveBezier2DState::MOVE_SPEED;
    this->asset->show();
    return;
}
void ArrowActiveBezier2DState::update(float delta) {
    float currentTime = this->frame->getFrameTime();
    Vec2 position = Bezier::create(currentTime, this->moveTime, this->owner->start->position, this->control, this->owner->goal->position);
    if (position == this->owner->goal->position) {
        this->owner->getStateMachine()->change("destroy");
        return;
    }
    this->asset->transform(position);
    float degree = (Degree::create(this->position, position) + ArrowActiveBezier2DState::DEFAULT_DEGREE) * -1;
    this->asset->transform(degree);
    this->position = position;
    if (false != this->owner->debug) {
        Layer* layer = this->owner->getLayer();
        GeographicUtility::drawDot(layer, position);
    }
    this->frame->setFrameTime(delta);
    return;
}
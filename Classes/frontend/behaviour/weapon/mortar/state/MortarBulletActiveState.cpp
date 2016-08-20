//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "MortarBulletActiveState.h"
// geography
#include "GeographicUtility.h"
#include "GeographicDepth.h"
#include "BehaviourCollection.h"
#include "Notifier.h"
#include "NotifyMessage.h"
// utility
#include "Degree.h"
#include "Distance.h"
#include "Coordinate.h"
// vfx
#include "Bezier.h"
#include "MotarSmokeEffectBehaviour.h"
#include "MotarLocusEffectBehaviour.h"
#include "BehaviourMapper.h"
#include "ServiceGateway.h"
#include "Response.h"
#include "Parameter.h"
using namespace cocos2d;
MortarBulletActiveState::MortarBulletActiveState() { this->damageStrategy = ServiceGateway::getInstance()->request("service://unit/damage"); }
MortarBulletActiveState::~MortarBulletActiveState() {}
void MortarBulletActiveState::create() {
    this->asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    this->asset->transform(this->owner->start->depth + GeographicDepth::WEAPON_DEPTH_RELATIVE_TO_NODE);
    this->position = this->owner->start->position;
    this->enableShot = true;
    this->start = this->owner->start->position + Vec2(0.0f, MortarBulletActiveState::SHOT_HEIGHT);
    Vec2 middlePoint = Coordinate::getMiddlePoint(this->owner->start->position, this->owner->goal->position);
    float distance = Distance::create(this->owner->start->position, this->owner->goal->position);
    float power = distance * MortarBulletActiveState::HEIGHT_RATE;
    this->control = middlePoint + Vec2(0, power);
    if (false != this->owner->debug) {
        Layer* layer = this->owner->getLayer();
        GeographicUtility::drawDot(layer, this->control);
    }
    this->moveTime = distance / MortarBulletActiveState::MOVE_SPEED;
    this->frame->reset();
    Position pos = Position(this->start, this->owner->start->depth + GeographicDepth::EFFECT_DEPTH_RELATIVE_TO_NODE);
    MotarSmokeEffectBehaviour effect;
    effect.onCreate(this->owner->getLayer(), pos);
    this->asset->show();
    return;
}
void MortarBulletActiveState::update(float delta) {
    float currentTime = this->frame->getFrameTime();
    Vec2 position = Bezier::create(currentTime, this->moveTime, this->start, this->control, this->owner->goal->position);
    this->asset->transform(position);
    if (position == this->owner->goal->position && false != this->enableShot) {
        int barrierId = this->owner->getProperty()->getId();
        BehaviourCollection* collection = BehaviourCollection::getInstance();
        Address address = this->owner->goal->address;
        std::vector<BaseUnitBehaviour*> ret = collection->findUnitByAddress(10, address);
        for (std::vector<BaseUnitBehaviour*>::iterator it = ret.begin(); it != ret.end(); it++) {
            int unitId = (*it)->getProperty()->getId();
            Parameter parameter;
            parameter.set<int>("unitId", unitId);
            parameter.set<int>("barrierId", barrierId);
            Response res = this->damageStrategy->update(&parameter);
            if (ServiceStatus::SUCCESS != res.getStatus()) {
                CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
            }
            res.clear();
        }
        this->owner->getStateMachine()->change("destroy");
        this->enableShot = false;
        return;
    }
    if (0 == this->frame->getFrame() % 10) {
        Position epos = Position(position, this->owner->start->depth + GeographicDepth::EFFECT_DEPTH_RELATIVE_TO_NODE);
        MotarLocusEffectBehaviour effect;
        effect.onCreate(this->owner->getLayer(), epos);
    }
    float degree = (Degree::create(this->position, position) + MortarBulletActiveState::DEFAULT_DEGREE) * -1;
    this->asset->transform(degree);
    this->position = position;
    if (false != this->owner->debug) {
        Layer* layer = this->owner->getLayer();
        GeographicUtility::drawDot(layer, position);
    }
    this->frame->update(delta, 1);
    return;
}
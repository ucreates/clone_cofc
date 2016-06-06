//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "CannonAttackState.h"

// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"

// behaviour
#include "BehaviourMapper.h"
#include "Transform.h"

// command
#include "CommandGateway.h"

// notify
#include "Notifier.h"
#include "NotifyMessage.h"

// vfx
#include "Liner.h"
#include "Quadratic.h"

// utility
#include "Distance.h"
#include "Position.h"
#include "BehaviourCollection.h"

using namespace cocos2d;

CannonAttackState::CannonAttackState(int ownerId) {
    this->shotFrame = new TimeLine();
    for (int i = 0; i < CannonAttackState::STOCKED_BULLET_NUMBER; i++) {
        this->stockedBulletVector.push_back(new CannonBulletBehaviour(NULL, ownerId, 0.0f));
    }
    this->stocledBulletCount = 0;
}

CannonAttackState::~CannonAttackState() {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    for (std::vector<CannonBulletBehaviour*>::iterator at = this->stockedBulletVector.begin(); at != this->stockedBulletVector.end(); at++) {
        collection->addClearVector((*at));
    }
    CC_SAFE_DELETE(this->shotFrame);
}

void CannonAttackState::create(Parameter* parameter) {
    BaseRenderAsset* asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    Transform transform = asset->getTransform();
    Position pos = transform.getPosition();
    this->origin = pos;
    float radian = CC_DEGREES_TO_RADIANS(0.0f);
    this->sin = sinf(radian);
    this->cos = cosf(radian);

    this->degree = parameter->get<int>("degree");
    this->shotDegree = parameter->get<float>("shotDegree");

    this->shotFrame->reset();
    this->frame->reset();
    return;
}

void CannonAttackState::update(float delta) {
    float currentFrameTime = this->frame->getFrameTime();
    BaseRenderAsset* asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    Transform transform = asset->getTransform();
    Position cpos = transform.getPosition();
    if (CannonAttackState::TRANSFORM_TIME <= currentFrameTime) {
        if (this->shotFrame->getFrameTime() > CannonAttackState::SHOT_TIME) {
            int index = this->stocledBulletCount % CannonAttackState::STOCKED_BULLET_NUMBER;
            CannonBulletBehaviour* bullet = this->stockedBulletVector.at(index);
            bullet->setProperty(this->owner->getGeographicNode(), this->shotDegree, true);
            this->stocledBulletCount++;
            BehaviourMapper::getInstance()->addMappingList(bullet, cpos);
            this->owner->getStateMachine()->change("search");
            this->shotFrame->reset();
            return;
        } else {
            this->shotFrame->setFrameTime(delta);
        }
        asset->transform(this->origin);
        asset->transform(Size(1.0f, 1.0f));
    } else {
        float dx = this->cos;
        float dy = this->sin;
        cpos.add(Vec2(dx, dy));
        asset->transform(cpos);

        float nextScale = Quadratic::easeIn(currentFrameTime, 1.0f, 1.25f, 0.1f);
        asset->transform(Size(nextScale, nextScale));

        this->frame->update(delta, 1);
    }
    return;
}
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "GiantAttackState.h"
// behaviour
#include "BaseOrnamentBehaviour.h"
#include "BehaviourCollection.h"
// utility
#include "Degree.h"
// math
#include "Random.h"
// geography
#include "GeographicNode.h"
// notify
#include "Notifier.h"
// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"
#include "ServiceGateway.h"
#include "Parameter.h"
#include "Response.h"
#include "Direction.h"
using namespace cocos2d;
GiantAttackState::GiantAttackState() { this->damageStrategy = ServiceGateway::getInstance()->request("service://barrier/damage"); }
GiantAttackState::~GiantAttackState() {}
void GiantAttackState::create(Parameter* parameter) {
    this->destroy = false;
    this->barrierNode = parameter->get<GeographicNode*>("barrier");
    if (0 != this->barrierNode->parentGeographicId) {
        GeographicGateway* gateway = GeographicGateway::getInstance();
        this->barrierNode = gateway->findByGeographicId(this->barrierNode->parentGeographicId);
    }
    this->targetBarrier = BehaviourCollection::getInstance()->findBarrierByAddress(this->barrierNode->address);
    if (NULL == this->targetBarrier) {
        this->destroy = true;
        return;
    }
    this->targetBarrierId = this->targetBarrier->getProperty()->getId();
    this->changeDirection();
    this->frame->reset();
    return;
}
void GiantAttackState::update(float delta) {
    if (false != this->destroy) {
        this->owner->getStateMachine()->change("move");
    } else {
        float waitTime = this->frame->getFrameTime();
        if (GiantAttackState::WAIT_TIME < waitTime) {
            this->changeDirection();
            this->frame->reset();
        }
        this->frame->setFrameTime(delta);
    }
}
void GiantAttackState::changeDirection() {
    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    Transform entity = asset->getTransform();
    Vec2 position = entity.getPosition().vector2d;
    float degree = Degree::create(position, this->barrierNode->position);
    Direction::DIRECT direction = Direction::getDirection(degree);
    if (direction == Direction::DIRECT::HORIZON_RIGHT) {
        this->selectAttackAnimation("side_attack", false);
    } else if (direction == Direction::DIRECT::HORIZON_LEFT) {
        this->selectAttackAnimation("side_attack", true);
    } else if (direction == Direction::DIRECT::UPPER_RIGHT) {
        this->selectAttackAnimation("upper_attack", false);
    } else if (direction == Direction::DIRECT::UPPER_LEFT) {
        this->selectAttackAnimation("upper_attack", true);
    } else if (direction == Direction::DIRECT::UNDER_RIGHT) {
        this->selectAttackAnimation("under_attack", false);
    } else if (direction == Direction::DIRECT::UNDER_LEFT) {
        this->selectAttackAnimation("under_attack", true);
    }
}
void GiantAttackState::selectAttackAnimation(std::string animationName, bool transform) {
    if (false != this->destroy) {
        return;
    }
    Parameter parameter;
    parameter.set<int>("barrierId", this->targetBarrierId);
    Response res = this->damageStrategy->get(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        this->destroy = true;
        res.clear();
        return;
    }
    int restHp = res.get<int>("restHp");
    if (restHp <= 0) {
        this->destroy = true;
        res.clear();
        return;
    }
    res.clear();
    std::string safix = "_01";
    int threshold = Random::create(10);
    if (0 == threshold % 2) {
        safix = "_02";
    }
    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    asset->play(animationName + safix, false);
    asset->transform(transform);
    threshold = Random::create(10);
    std::string seName = "se3";
    if (0 == threshold % 2) {
        seName = "se4";
    } else if (0 == threshold % 3) {
        seName = "se5";
    } else if (0 == threshold % 5) {
        seName = "se6";
    }
    SoundEffectAsset* se = (SoundEffectAsset*)this->owner->getAsset(seName.c_str());
    se->play();
    int unitId = this->owner->getProperty()->getId();
    parameter.set<int>("unitId", unitId);
    Notifier::getInstance()->notify(this->targetBarrierId, NotifyMessage::Behaviour_Barrier_Damage, &parameter);
}
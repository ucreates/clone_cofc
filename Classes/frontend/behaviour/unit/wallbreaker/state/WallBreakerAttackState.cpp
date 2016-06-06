//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "WallBreakerAttackState.h"

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
#include "NotifyMessage.h"
#include "Parameter.h"

// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"

#include "ServiceGateway.h"
#include "Parameter.h"
#include "Response.h"
#include "Direction.h"

using namespace cocos2d;

WallBreakerAttackState::WallBreakerAttackState() {}

WallBreakerAttackState::~WallBreakerAttackState() {}

void WallBreakerAttackState::create(Parameter* parameter) {
    this->barrierNode = parameter->get<GeographicNode*>("barrier");
    this->changeDirection();
    this->frame->reset();
    return;
}

void WallBreakerAttackState::update(float delta) {

    if (WallBreakerAttackState::WAIT_TIME < this->frame->getFrameTime() && false == this->complete) {
        std::vector<int> barrierIdVector;
        std::vector<BaseOrnamentBehaviour*> barrierVector = BehaviourCollection::getInstance()->findBarrierByAddress(5, this->barrierNode->address);
        for (std::vector<BaseOrnamentBehaviour*>::iterator it = barrierVector.begin(); it != barrierVector.end(); it++) {
            Parameter parameter;
            BaseOrnamentBehaviour* barrier = (BaseOrnamentBehaviour*)(*it);
            int id = barrier->getProperty()->getId();
            parameter.set<int>("barrierId", id);
            Notifier::getInstance()->notify(id, NotifyMessage::Behaviour_Barrier_Destroy, &parameter);
        }
        this->owner->getStateMachine()->change("dead");
        this->complete = true;
    } else {
        this->frame->setFrameTime(delta);
    }
    return;
}

void WallBreakerAttackState::changeDirection() {
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

void WallBreakerAttackState::selectAttackAnimation(std::string animationName, bool transform) {
    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    asset->stop();
    asset->play(animationName, false);
    asset->transform(transform);

    int threshold = Random::create(10);
    std::string seName = "se1";
    if (0 == threshold % 2) {
        seName = "se2";
    }
    SoundEffectAsset* se = (SoundEffectAsset*)this->owner->getAsset(seName.c_str());
    se->play();
}
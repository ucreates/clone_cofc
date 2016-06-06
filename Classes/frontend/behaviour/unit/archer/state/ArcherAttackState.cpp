//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "ArcherAttackState.h"

// behaviour
#include "BaseOrnamentBehaviour.h"
#include "BehaviourCollection.h"
#include "BehaviourMapper.h"

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

ArcherAttackState::ArcherAttackState(int ownerId) {
    this->stockedArrowVector.push_back(new ArrowBehaviour(NULL, NULL, ownerId));
    this->damageStrategy = ServiceGateway::getInstance()->request("service://barrier/damage");
}

ArcherAttackState::~ArcherAttackState() {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    for (std::vector<ArrowBehaviour*>::iterator at = this->stockedArrowVector.begin(); at != this->stockedArrowVector.end(); at++) {
        collection->addClearVector((*at));
    }
}

void ArcherAttackState::create(Parameter* parameter) {
    this->shotedArrowCount = 0;
    this->destroy = false;

    this->currentNode = parameter->get<GeographicNode*>("currentNode");
    this->barrierNode = parameter->get<GeographicNode*>("barrier");
    if (NULL == this->barrierNode) {
        this->destroy = true;
        return;
    }

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

void ArcherAttackState::changeDirection() {
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

void ArcherAttackState::update(float delta) {
    if (false != this->destroy) {
        AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
        asset->stop();
        for (std::vector<ArrowBehaviour*>::iterator at = this->stockedArrowVector.begin(); at != this->stockedArrowVector.end(); at++) {
            (*at)->onNotify(NotifyMessage::Behaviour_Weapon_Destroy);
        }
        this->owner->getStateMachine()->change("move");
    } else {
        float waitTime = this->frame->getFrameTime();
        if (ArcherAttackState::WAIT_TIME < waitTime) {
            this->changeDirection();
            this->frame->reset();
        }
        this->frame->setFrameTime(delta);
    }
}

void ArcherAttackState::selectAttackAnimation(std::string animationName, bool transform) {
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

    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    Scale scale = asset->getTransform().getScale();
    float height = scale.getHalfScale().height;
    ArrowBehaviour* arrow = this->stockedArrowVector.at(0);
    arrow->setProperty(this->currentNode, this->barrierNode, height, false);
    BehaviourMapper::getInstance()->addMappingList(arrow, this->currentNode->position, this->currentNode->depth);

    asset->play(animationName, false);
    asset->transform(transform);

    int threshold = Random::create(10);
    std::string seName = "se3";
    if (0 == threshold % 2) {
        seName = "se4";
    }
    SoundEffectAsset* se = (SoundEffectAsset*)this->owner->getAsset(seName.c_str());
    se->play();
}
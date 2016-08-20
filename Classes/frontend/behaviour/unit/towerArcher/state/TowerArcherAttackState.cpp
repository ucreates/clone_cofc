//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "TowerArcherAttackState.h"
// behaviour
#include "BaseOrnamentBehaviour.h"
#include "BehaviourCollection.h"
#include "BehaviourMapper.h"
// utility
#include "Degree.h"
#include "Distance.h"
// math
#include "Random.h"
// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
// notify
#include "Notifier.h"
// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"
#include "Direction.h"
#include "Response.h"
#include "ServiceGateway.h"
#include "ServiceStatus.h"
using namespace cocos2d;
TowerArcherAttackState::TowerArcherAttackState(int ownerId) {
    this->stockedArrowVector.push_back(new ArrowBehaviour(NULL, NULL, ownerId, 0.0f, true));
    this->damageStrategy = ServiceGateway::getInstance()->request("service://unit/damage");
}
TowerArcherAttackState::~TowerArcherAttackState() {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    for (std::vector<ArrowBehaviour*>::iterator at = this->stockedArrowVector.begin(); at != this->stockedArrowVector.end(); at++) {
        collection->addClearVector((*at));
    }
    this->stockedArrowVector.clear();
}
void TowerArcherAttackState::create(Parameter* parameter) {
    this->enableSearch = false;
    this->target = parameter->get<BaseBehaviour*>("unit");
    if (NULL == this->target) {
        this->enableSearch = true;
        return;
    }
    this->targetId = this->target->getProperty()->getId();
    this->changeDirection();
    this->frame->reset();
    return;
}
void TowerArcherAttackState::update(float delta) {
    float waitTime = this->frame->getFrameTime();
    if (TowerArcherAttackState::WAIT_TIME < waitTime) {
        AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
        asset->stop();
        for (std::vector<ArrowBehaviour*>::iterator at = this->stockedArrowVector.begin(); at != this->stockedArrowVector.end(); at++) {
            (*at)->onNotify(NotifyMessage::Behaviour_Weapon_Destroy);
        }
        Parameter parameter;
        parameter.set<Direction::DIRECT>("currentDirection", this->direction);
        this->owner->getStateMachine()->change("search", &parameter);
        this->frame->reset();
    }
    this->frame->setFrameTime(delta);
}
void TowerArcherAttackState::changeDirection() {
    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    Transform entity = asset->getTransform();
    Vec2 position = entity.getPosition().vector2d;
    GeographicNode* goal = this->target->getGeographicNode();
    if (NULL == goal) {
        return;
    }
    float degree = Degree::create(position, goal->position);
    this->direction = Direction::getDirection(degree);
    if (this->direction == Direction::DIRECT::HORIZON_RIGHT) {
        this->selectAttackAnimation("side_attack", false);
    } else if (this->direction == Direction::DIRECT::HORIZON_LEFT) {
        this->selectAttackAnimation("side_attack", true);
    } else if (this->direction == Direction::DIRECT::UPPER_RIGHT) {
        this->selectAttackAnimation("upper_attack", false);
    } else if (this->direction == Direction::DIRECT::UPPER_LEFT) {
        this->selectAttackAnimation("upper_attack", true);
    } else if (this->direction == Direction::DIRECT::UNDER_RIGHT) {
        this->selectAttackAnimation("under_attack", false);
    } else if (this->direction == Direction::DIRECT::UNDER_LEFT) {
        this->selectAttackAnimation("under_attack", true);
    }
}
void TowerArcherAttackState::selectAttackAnimation(std::string animationName, bool transform) {
    Parameter parameter;
    parameter.set<int>("unitId", this->targetId);
    Response res = this->damageStrategy->get(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        res.clear();
        return;
    }
    int restHp = res.get<int>("restHp");
    if (restHp <= 0) {
        res.clear();
        return;
    }
    res.clear();
    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    Transform at = asset->getTransform();
    GeographicNode* start = this->owner->getGeographicNode();
    GeographicNode* goal = this->target->getGeographicNode();
    Vec2 pos = at.getPosition().vector2d - start->position;
    ArrowBehaviour* arrow = this->stockedArrowVector.at(0);
    arrow->setProperty(start, goal, pos.y, true);
    int depth = this->owner->getGeographicNode()->depth;
    BehaviourMapper::getInstance()->addMappingList(arrow, pos, depth);
    asset->play(animationName, false);
    asset->transform(transform);
    SoundEffectAsset* se = (SoundEffectAsset*)this->owner->getAsset("se1");
    se->play();
}
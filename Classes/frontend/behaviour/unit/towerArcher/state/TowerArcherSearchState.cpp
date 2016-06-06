//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "TowerArcherSearchState.h"

// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"

// utility
#include "Distance.h"

// entity
#include "Transform.h"

// behaviour
#include "BehaviourCollection.h"
#include "Position.h"

TowerArcherSearchState::TowerArcherSearchState() {}

TowerArcherSearchState::~TowerArcherSearchState() {}

void TowerArcherSearchState::create() {
    this->changeDirection(Direction::DIRECT::UNDER_RIGHT);
    return;
}

void TowerArcherSearchState::create(Parameter* parameter) {
    Direction::DIRECT direction = parameter->get<Direction::DIRECT>("currentDirection");
    this->changeDirection(direction);
    return;
}

void TowerArcherSearchState::update(float delta) {
    BaseRenderAsset* oasset = (BaseRenderAsset*)this->owner->getAsset("anime");
    Transform transform = oasset->getTransform();
    Position pos1 = transform.getPosition();
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector("unit");
    for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        if (NULL != behaviour->getGeographicNode()) {
            BaseRenderAsset* asset = (BaseRenderAsset*)behaviour->getAsset("anime");
            Transform transform = asset->getTransform();
            Position pos2 = transform.getPosition();
            float distance = Distance::create(pos1.vector2d, pos2.vector2d);
            float thresholdDistance = GeographicGateway::getInstance()->getSize()->unitSize.width * 7;
            if (distance < thresholdDistance) {
                Parameter parameter;
                parameter.set<BaseBehaviour*>("unit", behaviour);
                this->owner->getStateMachine()->change("attack", &parameter);
                return;
            }
        }
    }
    return;
}

void TowerArcherSearchState::changeDirection(Direction::DIRECT direction) {
    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    if (direction == Direction::DIRECT::HORIZON_RIGHT) {
        asset->play("side_wait", false);
    } else if (direction == Direction::DIRECT::HORIZON_LEFT) {
        asset->play("side_wait", true);
    } else if (direction == Direction::DIRECT::UPPER_RIGHT) {
        asset->play("upper_wait", false);
    } else if (direction == Direction::DIRECT::UPPER_LEFT) {
        asset->play("upper_wait", true);
    } else if (direction == Direction::DIRECT::UNDER_RIGHT) {
        asset->play("under_wait", false);
    } else if (direction == Direction::DIRECT::UNDER_LEFT) {
        asset->play("under_wait", true);
    }
}
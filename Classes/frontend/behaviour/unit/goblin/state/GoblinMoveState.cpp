//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "GoblinMoveState.h"
#include "BarrierBehaviourType.h"

// geography
#include "GeographicNode.h"

// animator
#include "AnimatorAsset.h"
#include "BehaviourCollection.h"
#include "BarrierBehaviourType.h"

// utility
#include "Distance.h"

// entity
#include "Address.h"

GoblinMoveState::GoblinMoveState() {
    this->firstSearch = true;
    this->pause = false;
    this->speed = 1.2f;
}

GoblinMoveState::~GoblinMoveState() {}

void GoblinMoveState::create() {
    this->setUnit(this->owner);
    if (false != this->pause) {
        this->pause = false;
        this->changeDirection();
        return;
    }

    this->asset = (AnimatorAsset*)this->owner->getAsset("anime");
    this->owner->getStateMachine()->pause();
    this->search();
    return;
}

void GoblinMoveState::update(float delta) {
    if (false == this->routeVector.empty()) {
        std::vector<GeographicNode*>::iterator it = this->routeVector.begin();
        GeographicNode* node = (GeographicNode*)(*it);
        if (BarrierBehaviourType::None != node->type) {
            this->pause = true;
            GeographicNode* currentNode = this->owner->getGeographicNode();
            int distance = Distance::create(currentNode->address, node->address);
            if (distance == 1) {
                Parameter parameter;
                parameter.set<GeographicNode*>("barrier", node);
                this->owner->getStateMachine()->change("attack", &parameter);
            }
        } else {
            bool ret = this->move(node);
            if (false != ret) {
                this->routeVector.erase(it);
            }
        }
    } else {
        this->owner->getStateMachine()->change("move");
    }
    return;
}

GeographicNode* GoblinMoveState::findGoalNode(GeographicNode* startNode) {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    GeographicNode* node = collection->findBarrierByOrnamentType(startNode, "resource");
    if (NULL == node) {
        node = collection->findBarrierByPosition(startNode, true);
    }
    return node;
}

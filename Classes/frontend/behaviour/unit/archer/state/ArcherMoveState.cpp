//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "ArcherMoveState.h"

// geography
#include "GeographicNode.h"

// animator
#include "AnimatorAsset.h"

// utility
#include "Distance.h"

// notify
#include "Notifier.h"
#include "NotifyMessage.h"
#include "BarrierBehaviourType.h"
#include "BehaviourCollection.h"

ArcherMoveState::ArcherMoveState() {
    this->firstSearch = true;
    this->pause = false;
    this->speed = 1.0f;
}

ArcherMoveState::~ArcherMoveState() {}

void ArcherMoveState::create() {
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

void ArcherMoveState::update(float delta) {
    GeographicNode* targetNode = NULL;
    if (false == this->routeVector.empty()) {
        std::vector<GeographicNode*>::iterator it = this->routeVector.begin();
        GeographicNode* moveDestNode = (*it);

        if (NULL == targetNode) {
            for (std::vector<GeographicNode*>::iterator mt = this->routeVector.begin(); mt != this->routeVector.end(); mt++) {
                GeographicNode* node = (*mt);
                if (BarrierBehaviourType::None != node->type) {
                    targetNode = node;
                    break;
                }
            }
        }

        if (NULL != targetNode) {
            GeographicNode* currentNode = this->owner->getGeographicNode();
            float distance = Distance::create(currentNode->address, targetNode->address);
            if (distance <= 5) {
                this->pause = true;
                Parameter parameter;
                parameter.set<GeographicNode*>("currentNode", currentNode);
                parameter.set<GeographicNode*>("barrier", targetNode);
                this->owner->getStateMachine()->change("attack", &parameter);
                targetNode = NULL;
            } else {
                bool ret = this->move(moveDestNode);
                if (false != ret) {
                    this->routeVector.erase(it);
                }
            }
        } else {
            bool ret = this->move(moveDestNode);
            if (false != ret) {
                this->routeVector.erase(it);
            }
        }
    } else {
        this->owner->getStateMachine()->change("move");
    }
    return;
}
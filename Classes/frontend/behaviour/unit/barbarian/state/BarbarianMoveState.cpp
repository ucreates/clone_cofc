//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BarbarianMoveState.h"
#include "BarrierBehaviourType.h"
// geography
#include "GeographicNode.h"
// animator
#include "AnimatorAsset.h"
// utility
#include "Distance.h"
// entity
#include "Address.h"
#include "BarrierBehaviourType.h"
BarbarianMoveState::BarbarianMoveState() {
    this->firstSearch = true;
    this->pause = false;
    this->speed = 0.8f;
}
BarbarianMoveState::~BarbarianMoveState() {}
void BarbarianMoveState::create() {
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
void BarbarianMoveState::update(float delta) {
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

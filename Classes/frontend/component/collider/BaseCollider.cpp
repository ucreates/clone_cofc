//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BaseCollider.h"
using namespace cocos2d;

BaseCollider::BaseCollider() : BaseCollider(NULL, NULL) {}

BaseCollider::BaseCollider(BaseBehaviour* behaviour) : BaseCollider(behaviour, NULL) {}

BaseCollider::BaseCollider(GeographicNode* node) : BaseCollider(NULL, node) {}

BaseCollider::BaseCollider(BaseBehaviour* behaviour, GeographicNode* node) {
    this->behaviour = behaviour;
    this->node = node;
}

BaseCollider::~BaseCollider() {}

bool BaseCollider::isHit(float x, float y) {
    if (NULL != this->behaviour) {
        return this->isBehaviourHit(x, y);
    }

    if (NULL != this->node) {
        return this->isNodeHit(x, y);
    }

    return false;
}

bool BaseCollider::isHit(BaseBehaviour* behaviour) {
    if (NULL != this->behaviour) {
        return this->isBehaviourHit(behaviour);
    }

    if (NULL != this->node) {
        return this->isNodeHit(behaviour);
    }

    return false;
}

bool BaseCollider::isHit(Vec2 position) { return this->isHit(position.x, position.y); }

bool BaseCollider::isBehaviourHit(BaseBehaviour* behaviour) { return true; }

bool BaseCollider::isBehaviourHit(float x, float y) { return true; }

bool BaseCollider::isNodeHit(BaseBehaviour* behaviour) { return true; }

bool BaseCollider::isNodeHit(float x, float y) { return true; }

Node* BaseCollider::getGizmo() { return NULL; }
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "CircleCollider.h"
#include "Distance.h"
#include "ConvertUtility.h"

using namespace cocos2d;

CircleCollider::CircleCollider() : CircleCollider(NULL, NULL) {}

CircleCollider::CircleCollider(BaseBehaviour* behaviour) : CircleCollider(behaviour, NULL) {}

CircleCollider::CircleCollider(GeographicNode* node) : CircleCollider(NULL, node) {}

CircleCollider::CircleCollider(BaseBehaviour* behaviour, GeographicNode* node) {
    this->behaviour = behaviour;
    this->node = node;
    if (NULL != this->node) {
        Size size = this->node->scale->getHalfScale();
        this->radius = MAX(size.width, size.height);
    }
}

CircleCollider::~CircleCollider() {}

bool CircleCollider::isBehaviourHit(BaseBehaviour* behaviour) {
    BaseRenderAsset* pbra = (BaseRenderAsset*)behaviour->getAsset("anime");
    Position pos1 = pbra->getTransform().getPosition();

    BaseRenderAsset* bra = (BaseRenderAsset*)this->behaviour->getAsset("anime");
    Position pos2 = bra->getTransform().getPosition();
    float distance = Distance::create(pos1.vector2d, pos2.vector2d);
    return (distance <= this->radius);
}

bool CircleCollider::isNodeHit(BaseBehaviour* behaviour) {
    BaseRenderAsset* pbra = (BaseRenderAsset*)behaviour->getAsset("anime");
    Position pos1 = pbra->getTransform().getPosition();
    Position pos2 = Position(this->node->position, this->node->depth);
    float distance = Distance::create(pos1, pos2);
    return (distance <= this->radius);
}

bool CircleCollider::isNodeHit(float x, float y) {
    float distance = Distance::create(Vec2(x, y), this->node->position);
    return (distance <= this->radius);
}

Node* CircleCollider::getGizmo() {
    DrawNode* node = DrawNode::create();
    Vec2 cpos;
    if (NULL != this->behaviour) {
        BaseRenderAsset* bra = (BaseRenderAsset*)this->behaviour->getAsset("anime");
        cpos = bra->getTransform().getPosition().vector2d;
    } else if (NULL != this->node) {
        cpos = this->node->position;
    }
    node->drawDot(Vec2(0, 0), this->radius, Color4F(0.0f, 1.0f, 0.0f, 0.5f));
    node->setPosition(cpos);
    return node;
}

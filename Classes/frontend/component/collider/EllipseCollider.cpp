//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "EllipseCollider.h"

// utility
#include "Distance.h"
#include "ConvertUtility.h"
#include "Radian.h"

using namespace cocos2d;

EllipseCollider::EllipseCollider() : EllipseCollider(NULL, NULL) {}

EllipseCollider::EllipseCollider(BaseBehaviour* behaviour) : EllipseCollider(behaviour, NULL) {}

EllipseCollider::EllipseCollider(GeographicNode* node) : EllipseCollider(NULL, node) {}

EllipseCollider::EllipseCollider(BaseBehaviour* behaviour, GeographicNode* node) {
    this->behaviour = behaviour;
    this->node = node;
}

EllipseCollider::~EllipseCollider() {}

bool EllipseCollider::isBehaviourHit(BaseBehaviour* behaviour) {

    BaseRenderAsset* pbra = (BaseRenderAsset*)behaviour->getAsset("anime");
    Position pos1 = pbra->getTransform().getPosition();

    BaseRenderAsset* bra = (BaseRenderAsset*)this->behaviour->getAsset("anime");
    Transform transform = bra->getTransform();
    Size size2 = transform.getContentsScale().getHalfScale();
    Position pos2 = transform.getPosition();

    float radian = Radian::create(pos1, pos2);
    float ex = pos2.x + sin(radian) * size2.width;
    float ey = pos2.y + cos(radian) * size2.height;
    Position cpos(pos2.vector2d, 0);
    Position epos(Vec2(ex, ey), 0);
    float radius = Distance::create(cpos, epos);
    float distance = Distance::create(pos2, pos1);
    return (distance <= radius);
}

bool EllipseCollider::isNodeHit(BaseBehaviour* behaviour) {

    BaseRenderAsset* pbra = (BaseRenderAsset*)behaviour->getAsset("anime");
    Position pos1 = pbra->getTransform().getPosition();

    Position pos2 = Position(this->node->position, this->node->depth);
    Size size2 = this->node->scale->getHalfScale();

    float radian = Radian::create(pos1, pos2);
    float ex = pos2.x + sin(radian) * size2.width;
    float ey = pos2.y + cos(radian) * size2.height;
    Position cpos(pos2.vector2d, 0);
    Position epos(Vec2(ex, ey), 0);
    float radius = Distance::create(cpos, epos);
    float distance = Distance::create(pos2, pos1);
    return (distance <= radius);
}

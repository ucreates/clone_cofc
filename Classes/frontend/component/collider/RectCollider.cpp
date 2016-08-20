//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "RectCollider.h"
#include "Transform.h"
#include "Scale.h"
#include "ConvertUtility.h"
using namespace cocos2d;
RectCollider::RectCollider() : RectCollider(NULL, NULL) {}
RectCollider::RectCollider(BaseBehaviour* behaviour) : RectCollider(behaviour, NULL) {}
RectCollider::RectCollider(GeographicNode* node) : RectCollider(NULL, node) {}
RectCollider::RectCollider(BaseBehaviour* behaviour, GeographicNode* node) {
    this->behaviour = behaviour;
    this->node = node;
}
RectCollider::~RectCollider() {}
bool RectCollider::isBehaviourHit(BaseBehaviour* behaviour) {
    BaseRenderAsset* pbra = (BaseRenderAsset*)behaviour->getAsset("anime");
    Transform transform1 = pbra->getTransform();
    Position pos1 = transform1.getPosition();
    BaseRenderAsset* bra = (BaseRenderAsset*)this->behaviour->getAsset("anime");
    Transform transform2 = bra->getTransform();
    Size size2 = transform2.getContentsScale().getHalfScale();
    Position pos2 = transform2.getPosition();
    float sx = pos2.x - size2.width;
    float ex = pos2.x + size2.width;
    float sy = pos2.y - size2.height;
    float ey = pos2.y + size2.height;
    return (sx <= pos1.x && pos1.x <= ex && sy <= pos1.y && pos1.y <= ey);
}
bool RectCollider::isNodeHit(BaseBehaviour* behaviour) {
    BaseRenderAsset* pbra = (BaseRenderAsset*)behaviour->getAsset("anime");
    Position pos1 = pbra->getTransform().getPosition();
    Vec2 pos2 = this->node->position;
    Scale* scale = this->node->scale;
    float width = scale->getHalfScale().width;
    float height = scale->getHalfScale().height;
    float sx = pos2.x - width;
    float ex = pos2.x + width;
    float sy = pos2.y + height;
    float ey = pos2.y - height;
    return (sx <= pos1.x && pos1.x <= ex && sy <= pos1.y && pos1.y <= ey);
}
void RectCollider::addLayer(Layer* layer, int depth) {
    DrawNode* node = DrawNode::create();
    Vec2 origin = Vec2::ZERO;
    Vec2 dest = Vec2::ZERO;
    Vec2 cpos = Vec2::ZERO;
    if (NULL != this->behaviour) {
        BaseRenderAsset* pbra = (BaseRenderAsset*)this->behaviour->getAsset("anime");
        Transform transform = pbra->getTransform();
        cpos = transform.getPosition().vector2d;
        Size allSize = transform.getContentsScale().getAllScale();
        Size halfSize = transform.getContentsScale().getHalfScale();
        origin = Vec2(-1 * halfSize.width, -1 * halfSize.height);
        dest = Vec2(allSize.width, allSize.height);
    } else if (NULL != this->node) {
        cpos = this->node->position;
        Vec2 position = this->node->position;
        Scale* scale = this->node->scale;
        float width = scale->getHalfScale().width;
        float height = scale->getHalfScale().height;
        dest = Vec2(width, height);
    }
    node->drawRect(origin, dest, Color4F(0.0f, 1.0f, 0.0f, 0.5f));
    node->setPosition(cpos);
    layer->addChild(node, depth);
}
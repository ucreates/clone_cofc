//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BaseRenderAsset.h"
using namespace cocos2d;
BaseRenderAsset::BaseRenderAsset() {
    this->type = "render";
    this->node = NULL;
}
BaseRenderAsset::~BaseRenderAsset() {
    if (NULL != this->node) {
        this->node->removeFromParentAndCleanup(true);
    }
}
Node* BaseRenderAsset::getNode() { return this->node; }
Transform BaseRenderAsset::getTransform() {
    Vec2 cpos = this->node->getPosition();
    int zorder = this->node->getLocalZOrder();
    float sx = this->node->getScaleX();
    float sy = this->node->getScaleY();
    Size scale = Size(sx, sy);
    Size cscale = this->node->getContentSize();
    float rotate = this->node->getRotation();
    GLubyte alpha = this->node->getOpacity();
    Transform entity = Transform(cpos, zorder, scale, cscale, rotate, alpha);
    return entity;
}
void BaseRenderAsset::transform(Vec2 position) { this->node->setPosition(position); }
void BaseRenderAsset::transform(Vec2 position, OrnamentProperty* property) { this->node->setPosition(position.x, position.y + property->getScale()->getHalfScale().height); }
void BaseRenderAsset::transform(Position position) {
    this->node->setPosition(position.x, position.y);
    this->node->setLocalZOrder(position.zorder);
}
void BaseRenderAsset::transform(Position position, OrnamentProperty* property) {
    this->node->setPosition(position.x, position.y + property->getScale()->getHalfScale().height);
    this->node->setLocalZOrder(position.zorder);
}
void BaseRenderAsset::transform(GeographicNode* node) { this->node->setPosition(node->position.x, node->position.y); }
void BaseRenderAsset::transform(GeographicNode* node, int depth) {
    this->node->setPosition(node->position.x, node->position.y);
    this->node->setLocalZOrder(depth);
}
void BaseRenderAsset::transform(GeographicNode* node, OrnamentProperty* property, int depth) {
    this->node->setPosition(node->position.x, node->position.y + property->getScale()->getHalfScale().height);
    this->node->setLocalZOrder(depth);
}
void BaseRenderAsset::transform(int zorder) { this->node->setLocalZOrder(zorder); }
void BaseRenderAsset::transform(float x, float y) { this->node->setPosition(x, y); }
void BaseRenderAsset::transform(float x, float y, int z) {
    this->node->setPosition(x, y);
    this->node->setLocalZOrder(z);
}
void BaseRenderAsset::transform(Size* scale) { this->node->setScale(scale->width, scale->height); }
void BaseRenderAsset::transform(Size scale) { this->transform(&scale); }
void BaseRenderAsset::transform(float rotate) { this->node->setRotation(rotate); }
void BaseRenderAsset::transform(GLubyte alpha) { this->node->setOpacity(alpha); }
void BaseRenderAsset::transform(float x, float y, int z, float width, float height, float rotate, GLubyte alpha, bool dump) {
    this->node->setPosition(x, y);
    this->node->setScale(width, height);
    this->node->setLocalZOrder(z);
    this->node->setRotation(rotate);
    this->node->setOpacity(alpha);
    if (false != dump) {
        Vec2 position = this->node->getPosition();
        float scalex = this->node->getScaleX();
        float scaley = this->node->getScaleY();
        int zorder = this->node->getLocalZOrder();
        float rotation = this->node->getRotation();
        GLubyte opacity = this->node->getOpacity();
        DEBUG_VECTOR2("position", position);
        DEBUG_VECTOR2("scale", Vec2(scalex, scaley));
        DEBUG_INT("zorder", zorder);
        DEBUG_FLOAT("rotation", rotation);
        DEBUG_GLUBYTE("opacity", opacity);
    }
    return;
}
void BaseRenderAsset::transform(bool transform) {
    float scale = this->node->getScaleX();
    bool minus = scale < 0.0f ? true : false;
    if (false != transform) {
        if (false == minus) {
            scale *= -1.0f;
        }
    } else {
        if (false != minus) {
            scale *= -1.0f;
        }
    }
    this->node->setScaleX(scale);
}
void BaseRenderAsset::show() { this->node->setVisible(true); }
void BaseRenderAsset::hide() { this->node->setVisible(false); }
void BaseRenderAsset::addLayer(Layer* layer, int depth) { layer->addChild(this->node, depth); }
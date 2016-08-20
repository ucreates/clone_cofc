//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "GeographicNode.h"
#include "CircleCollider.h"
using namespace cocos2d;
GeographicNode::GeographicNode() {
    this->depth = 0;
    this->type = 0;
    this->geographicId = 0;
    this->parentGeographicId = 0;
    this->position = Vec2::ZERO;
    this->address = Address::ZERO;
    this->scale = new Scale(Size(50.0f, 50.0f));
    this->collider = new CircleCollider(this);
}
GeographicNode::~GeographicNode() {
    CC_SAFE_DELETE(this->scale);
    CC_SAFE_DELETE(this->collider);
}
void GeographicNode::dump(Layer* layer, int depth) {
    Label* label = Label::create();
    label->setString(ConvertUtility::toString(this->depth));
    label->setPosition(this->position);
    layer->addChild(label, depth);
}
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// utility
#include "GeographicUtility.h"
using namespace cocos2d;
void GeographicUtility::drawDepth(Layer* layer, GeographicNode* node) {
    std::ostringstream depth;
    depth << node->depth;
    Label* label = Label::createWithSystemFont(depth.str(), "HiraKakuProN-W6", 10);
    label->setPosition(node->position);
    layer->addChild(label, GeographicUtility::DRAW_DEPTH);
}
void GeographicUtility::drawDot(cocos2d::Layer* layer, Vec2 position) {
    DrawNode* node = DrawNode::create();
    node->drawDot(Vec2(0, 0), 10, Color4F(1.0f, 0.0f, 0.0f, 0.5f));
    node->setPosition(position);
    layer->addChild(node, GeographicUtility::DRAW_DOT_DEPTH);
}

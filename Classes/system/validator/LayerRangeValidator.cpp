//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// math
#include "Range.h"

// validator
#include "LayerRangeValidator.h"

using namespace cocos2d;

LayerRangeValidator::LayerRangeValidator() {}

LayerRangeValidator::~LayerRangeValidator() {}

bool LayerRangeValidator::isValid() {
    float layerScale = this->layer->getScale();
    float scale = 1.0f / layerScale;
    Rect range = Range::getLayerRange(scale);
    if (range.getMinX() <= this->position.x && this->position.x <= range.getMaxX() && range.getMinY() <= this->position.y && this->position.y <= range.getMaxY()) {
        return true;
    }
    return false;
}

void LayerRangeValidator::setProperty(Position position, cocos2d::Layer* layer) {
    this->position = position;
    this->layer = layer;
}

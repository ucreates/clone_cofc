//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// entity
#include "Scale.h"

using namespace cocos2d;
Scale::Scale() {}

Scale::Scale(Size scale) { this->update(scale); }

Scale::~Scale() {}

Size Scale::getAllScale() { return this->scale; }

Size Scale::getHalfScale() { return this->halfScale; }

void Scale::update(Size scale) {
    this->scale.width = scale.width;
    this->scale.height = scale.height;
    this->halfScale.width = scale.width * 0.5;
    this->halfScale.height = scale.height * 0.5;
}
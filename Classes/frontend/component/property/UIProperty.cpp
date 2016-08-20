//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "UIProperty.h"
UIProperty::UIProperty(std::string name, int id) {
    this->name = name;
    this->id = id;
    this->type = "ui";
}
UIProperty::~UIProperty() {}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BaseProperty.h"

BaseProperty::BaseProperty() {
    this->name = "";
    this->id = 0;
    this->type = "unknown";
    this->status = BehaviourStatus::ACTIVE;
}

BaseProperty::~BaseProperty() {}

std::string BaseProperty::getName() { return this->name; }

std::string BaseProperty::getType() { return this->type; }

int BaseProperty::getId() { return this->id; }

BehaviourStatus BaseProperty::getStatus() { return this->status; }

void BaseProperty::setStatus(BehaviourStatus status) { this->status = status; }
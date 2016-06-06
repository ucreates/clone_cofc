//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BarbarianDeadState.h"

BarbarianDeadState::BarbarianDeadState() {}

BarbarianDeadState::~BarbarianDeadState() {}

void BarbarianDeadState::create() {
    this->dead(this->owner);
    return;
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "GoblinDeadState.h"
GoblinDeadState::GoblinDeadState() {}
GoblinDeadState::~GoblinDeadState() {}
void GoblinDeadState::create() {
    this->dead(this->owner);
    return;
}

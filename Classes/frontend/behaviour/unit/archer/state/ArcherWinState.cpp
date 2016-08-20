//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "ArcherWinState.h"
// geography
#include "GeographicNode.h"
// animator
#include "AnimatorAsset.h"
// utility
#include "Degree.h"
ArcherWinState::ArcherWinState() {}
ArcherWinState::~ArcherWinState() {}
void ArcherWinState::create() {
    this->changeDirection(this->owner);
    return;
}

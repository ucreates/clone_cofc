//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BaseAsset.h"

BaseAsset::BaseAsset() { this->id = 0; }

BaseAsset::~BaseAsset() {}

std::string BaseAsset::getType() { return this->type; }

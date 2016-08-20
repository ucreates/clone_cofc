//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// service
#include "BaseTable.h"
BaseTable::BaseTable() { this->id = 0; }
void BaseTable::build() { return; }
void BaseTable::clear() { this->compareFieldIterator.clear(); }
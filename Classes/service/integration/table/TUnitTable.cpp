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
#include "TUnitTable.h"
#include "FieldSchema.h"

TUnitTable::TUnitTable() {
    this->unitId = -1;
    this->type = -1;
    this->hp = 0;
    this->power = 0;
}

void TUnitTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("unitId", new FieldSchema<int>(this->unitId));
    this->compareFieldIterator.set("type", new FieldSchema<int>(this->type));
    this->compareFieldIterator.set("hp", new FieldSchema<int>(this->hp));
    this->compareFieldIterator.set("power", new FieldSchema<int>(this->power));
}

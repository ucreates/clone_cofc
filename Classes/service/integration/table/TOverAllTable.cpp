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
#include "TOverAllTable.h"
#include "FieldSchema.h"

TOverAllTable::TOverAllTable() {
    this->current = 0;
    this->total = 0;
    this->reachedLevel1 = false;
    this->reachedLevel2 = false;
    this->reachedLevel3 = false;
}

void TOverAllTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("layer", new FieldSchema<int>(this->current));
    this->compareFieldIterator.set("layerId", new FieldSchema<int>(this->total));
    this->compareFieldIterator.set("reachedLevel1", new FieldSchema<bool>(this->reachedLevel1));
    this->compareFieldIterator.set("reachedLevel2", new FieldSchema<bool>(this->reachedLevel2));
    this->compareFieldIterator.set("reachedLevel3", new FieldSchema<bool>(this->reachedLevel3));
}

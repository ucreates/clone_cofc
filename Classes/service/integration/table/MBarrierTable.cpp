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
#include "MBarrierTable.h"
#include "FieldSchema.h"
MBarrierTable::MBarrierTable() {
    this->name = "";
    this->type = 0;
    this->hp = 0;
    this->power = 0;
}
void MBarrierTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("name", new FieldSchema<std::string>(this->name));
    this->compareFieldIterator.set("type", new FieldSchema<int>(this->type));
    this->compareFieldIterator.set("hp", new FieldSchema<int>(this->hp));
    this->compareFieldIterator.set("power", new FieldSchema<int>(this->power));
}

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
#include "MResourceTable.h"
#include "FieldSchema.h"
MResourceTable::MResourceTable() {
    this->emerald = 0;
    this->gold = 0;
    this->elixir = 0;
}
void MResourceTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("emerald", new FieldSchema<int>(this->emerald));
    this->compareFieldIterator.set("gold", new FieldSchema<int>(this->gold));
    this->compareFieldIterator.set("elixir", new FieldSchema<int>(this->elixir));
}

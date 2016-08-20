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
#include "TAssetTable.h"
#include "FieldSchema.h"
TAssetTable::TAssetTable() {
    this->name = "";
    this->type = "";
    this->path = "";
}
void TAssetTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("name", new FieldSchema<std::string>(this->name));
    this->compareFieldIterator.set("type", new FieldSchema<std::string>(this->type));
    this->compareFieldIterator.set("path", new FieldSchema<std::string>(this->path));
}

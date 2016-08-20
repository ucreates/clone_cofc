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
#include "TDownLoadTable.h"
#include "FieldSchema.h"
TDownLoadTable::TDownLoadTable() {
    this->emitDownLoad = false;
    this->isAssetCache = false;
    this->current = 0;
    this->total = 0;
}
void TDownLoadTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("emitDownLoad", new FieldSchema<bool>(this->emitDownLoad));
    this->compareFieldIterator.set("isAssetCache", new FieldSchema<bool>(this->isAssetCache));
    this->compareFieldIterator.set("current", new FieldSchema<int>(this->current));
    this->compareFieldIterator.set("total", new FieldSchema<int>(this->total));
}

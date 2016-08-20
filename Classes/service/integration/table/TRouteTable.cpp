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
#include "TRouteTable.h"
#include "FieldSchema.h"
TRouteTable::TRouteTable() {
    this->startGeographicId = 0;
    this->goalGeographicId = 0;
}
void TRouteTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("startGeographicId", new FieldSchema<int>(this->startGeographicId));
    this->compareFieldIterator.set("goalGeographicId", new FieldSchema<int>(this->goalGeographicId));
}

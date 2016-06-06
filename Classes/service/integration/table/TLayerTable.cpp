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
#include "TLayerTable.h"
#include "FieldSchema.h"

using namespace cocos2d;
TLayerTable::TLayerTable() {
    this->layer = NULL;
    this->layerId = 0;
}

void TLayerTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("layer", new FieldSchema<Layer*>(this->layer));
    this->compareFieldIterator.set("layerId", new FieldSchema<int>(this->layerId));
}

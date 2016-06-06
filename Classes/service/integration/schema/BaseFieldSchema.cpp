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
#include "BaseFieldSchema.h"

BaseFieldSchema::BaseFieldSchema() {}

BaseFieldSchema::~BaseFieldSchema() {}

bool BaseFieldSchema::equal(BaseFieldSchema* field) { return true; }

bool BaseFieldSchema::moreThan(BaseFieldSchema* field) { return true; }

bool BaseFieldSchema::moreThanEqual(BaseFieldSchema* field) { return true; }

bool BaseFieldSchema::lessThan(BaseFieldSchema* field) { return true; }

bool BaseFieldSchema::lessThanEqual(BaseFieldSchema* field) { return true; }

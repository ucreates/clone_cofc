//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseTable_h
#define BaseTable_h
// service
#include "KeySchema.h"
#include "FieldSchemaCollection.h"
class BaseTable {
   public:
    KeySchema primaryKey;
    KeySchema foreignKey;
    FieldSchemaCollection compareFieldIterator;
    int id;
    BaseTable();
    virtual void build();
    void clear();
};
#endif

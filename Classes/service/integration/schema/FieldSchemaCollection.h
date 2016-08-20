//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef FieldSchemaCollection_h
#define FieldSchemaCollection_h
// stl
#include <map>
#include <string>
// service
#include "BaseFieldSchema.h"
class FieldSchemaCollection {
   public:
    BaseFieldSchema* get(std::string fieldName);
    bool set(std::string fieldName, BaseFieldSchema* field);
    std::map<std::string, BaseFieldSchema*> getFieldSchemaMap();
    void clear();
   private:
    std::map<std::string, BaseFieldSchema*> fieldList;
};
#endif

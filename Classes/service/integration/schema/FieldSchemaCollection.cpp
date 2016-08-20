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
#include "cocos2d.h"
#include "FieldSchemaCollection.h"
BaseFieldSchema* FieldSchemaCollection::get(std::string fieldName) {
    if (this->fieldList.end() == this->fieldList.find(fieldName)) {
        return NULL;
    }
    return this->fieldList[fieldName];
}
bool FieldSchemaCollection::set(std::string fieldName, BaseFieldSchema* field) {
    if (this->fieldList.end() == this->fieldList.find(fieldName)) {
        this->fieldList.insert(std::map<std::string, BaseFieldSchema*>::value_type(fieldName, field));
        return true;
    }
    return false;
}
void FieldSchemaCollection::clear() {
    std::map<std::string, BaseFieldSchema*>::iterator it = this->fieldList.begin();
    while (it != this->fieldList.end()) {
        CC_SAFE_DELETE(it->second);
        it++;
    }
    this->fieldList.clear();
}
std::map<std::string, BaseFieldSchema*> FieldSchemaCollection::getFieldSchemaMap() { return this->fieldList; }

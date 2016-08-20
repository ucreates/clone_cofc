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
#include "KeySchema.h"
// utility
#include "ConvertUtility.h"
std::string KeySchema::get() {
    if (0 != this->key.length()) {
        return this->key;
    }
    std::map<std::string, std::string>::iterator it = this->keyHolderMap.begin();
    while (it != this->keyHolderMap.end()) {
        this->key += (*it).second;
        it++;
    }
    return this->key;
}
std::string KeySchema::get(std::string fieldName) {
    if (0 != this->keyHolderMap.count(fieldName)) {
        return this->keyHolderMap[fieldName];
    }
    return NULL;
}
int KeySchema::getId() {
    if (0 == this->keyHolderMap.count("id")) {
        return 0;
    }
    return ConvertUtility::toInt(this->keyHolderMap["id"]);
}
std::map<std::string, std::string> KeySchema::getKeyHolder() { return this->keyHolderMap; }
bool KeySchema::set(std::string fieldName, std::string fieldValue) {
    if (0 != this->keyHolderMap.count(fieldName)) {
        return false;
    }
    this->keyHolderMap.insert(std::map<std::string, std::string>::value_type(fieldName, fieldValue));
    return true;
}
bool KeySchema::set(std::string fieldName, int fieldValue) { return this->set(fieldName, ConvertUtility::toString(fieldValue)); }
bool KeySchema::operator==(KeySchema &key) {
    std::map<std::string, std::string> keyHolderMap = key.getKeyHolder();
    std::map<std::string, std::string>::iterator it = keyHolderMap.begin();
    while (it != keyHolderMap.end()) {
        if (0 == this->keyHolderMap.count((*it).first)) {
            return false;
        }
        std::string val = this->keyHolderMap[(*it).first];
        if (val != (*it).second) {
            return false;
        }
        it++;
    }
    return true;
}
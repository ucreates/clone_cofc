//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// cocos2d
#include "cocos2d.h"

// service
#include "FieldSchema.h"

using namespace cocos2d;

template <typename T>
FieldSchema<T>::FieldSchema() {}

template <typename T>
FieldSchema<T>::FieldSchema(T value) {
    this->value = value;
}

template <typename T>
FieldSchema<T>::~FieldSchema() {}

template <typename T>
T FieldSchema<T>::getValue() {
    return this->value;
}

template <typename T>
void FieldSchema<T>::setValue(T value) {
    this->value = value;
}

template <typename T>
bool FieldSchema<T>::equal(BaseFieldSchema* field) {
    FieldSchema<T>* cmp = (FieldSchema<T>*)field;
    return (this->value == cmp->getValue());
}

template <typename T>
bool FieldSchema<T>::moreThan(BaseFieldSchema* field) {
    FieldSchema<T>* cmp = (FieldSchema<T>*)field;
    return (this->value > cmp->getValue());
}

template <typename T>
bool FieldSchema<T>::moreThanEqual(BaseFieldSchema* field) {
    FieldSchema<T>* cmp = (FieldSchema<T>*)field;
    return (this->value >= cmp->getValue());
}

template <typename T>
bool FieldSchema<T>::lessThan(BaseFieldSchema* field) {
    FieldSchema<T>* cmp = (FieldSchema<T>*)field;
    return (this->value < cmp->getValue());
}

template <typename T>
bool FieldSchema<T>::lessThanEqual(BaseFieldSchema* field) {
    FieldSchema<T>* cmp = (FieldSchema<T>*)field;
    return (this->value <= cmp->getValue());
}

template class FieldSchema<int>;
template class FieldSchema<long>;
template class FieldSchema<float>;
template class FieldSchema<double>;
template class FieldSchema<std::string>;
template class FieldSchema<bool>;
template class FieldSchema<Layer*>;

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Value_h
#define Value_h
// entity
#include "BaseValue.h"
template <typename T>
class Value : public BaseValue {
   public:
    inline Value() {}
    inline virtual ~Value() {}
    inline T getValue() { return this->value; }
    inline void setValue(T value) { this->value = value; }
    inline BaseValue* clone() override { return new Value<T>(*this); }
   private:
    T value;
};
#endif

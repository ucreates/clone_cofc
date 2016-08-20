//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseValue_h
#define BaseValue_h
class BaseValue {
   public:
    inline BaseValue() {}
    inline virtual ~BaseValue() {}
    inline virtual BaseValue* clone() { return new BaseValue(*this); }
};
#endif

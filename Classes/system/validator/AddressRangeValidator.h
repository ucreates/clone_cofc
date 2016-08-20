//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef AddressRangeValidator_h
#define AddressRangeValidator_h
// entity
#include "Address.h"
// validator
#include "BaseValidator.h"
class AddressRangeValidator : public BaseValidator {
   public:
    AddressRangeValidator();
    ~AddressRangeValidator();
    bool isValid() override;
    void setProperty(Address address);
   private:
    Address address;
};
#endif

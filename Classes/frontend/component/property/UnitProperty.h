//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef UnitProperty_h
#define UnitProperty_h

#include "BaseProperty.h"

class UnitProperty : public BaseProperty {
   public:
    UnitProperty(std::string name, int id);
    virtual ~UnitProperty();
};

#endif

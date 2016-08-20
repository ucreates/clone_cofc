//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UIProperty_h
#define UIProperty_h
#include "BaseProperty.h"
class UIProperty : public BaseProperty {
   public:
    UIProperty(std::string name, int id);
    virtual ~UIProperty();
};
#endif

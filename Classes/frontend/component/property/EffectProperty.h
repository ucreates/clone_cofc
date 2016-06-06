//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef EffectProperty_h
#define EffectProperty_h

#include "BaseProperty.h"

class EffectProperty : public BaseProperty {
   public:
    EffectProperty(std::string name, int id);
    virtual ~EffectProperty();
};

#endif

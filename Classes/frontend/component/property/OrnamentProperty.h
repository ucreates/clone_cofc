//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef OrnamentProperty_h
#define OrnamentProperty_h

#include "Scale.h"
#include "Address.h"
#include "BaseProperty.h"

class OrnamentProperty : public BaseProperty {
   public:
    OrnamentProperty(std::string name, int id, std::string ornamentType, float xscale, float yscale, float zscale);
    virtual ~OrnamentProperty();
    Scale* getScale();
    Address* getAddressScale();
    std::string getOrnamentType();

   private:
    Scale* scale;
    Address* addressScale;
    std::string ornamentType;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseAsset_h
#define BaseAsset_h
#include <string>

class BaseAsset {
   public:
    BaseAsset();
    virtual ~BaseAsset();
    std::string getType();

   protected:
    unsigned int id;
    std::string type;
};

#endif

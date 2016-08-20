//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataSreamFactory_h
#define GeographicDataSreamFactory_h
// stream
#include "GeographicDataBaseFormatStream.h"
class GeographicDataSreamFactory {
   public:
    static GeographicDataBaseFormatStream* factoryMethod(unsigned char formatType);
};
#endif

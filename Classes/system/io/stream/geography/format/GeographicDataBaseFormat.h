//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataBaseFormat_h
#define GeographicDataBaseFormat_h
#include "GeographicNode.h"
class GeographicDataBaseFormat {
   public:
    static const char HEADER = 0x00;
    static const char FIELD = 0x01;
    static const char BARRIER = 0x02;
    GeographicDataBaseFormat();
    virtual ~GeographicDataBaseFormat();
    virtual void build();
   protected:
    GeographicNode* node;
};
#endif

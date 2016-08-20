//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataFieldTag_h
#define GeographicDataFieldTag_h
// stream
#include "GeographicDataBaseTag.h"
#include "GeographicDataRecordHeader.h"
class GeographicDataFieldTag : public GeographicDataBaseTag {
   public:
    unsigned char mapTipType;
    GeographicDataFieldTag();
    GeographicDataFieldTag(GeographicNode* node);
    virtual ~GeographicDataFieldTag();
    void build() override;
};
#endif

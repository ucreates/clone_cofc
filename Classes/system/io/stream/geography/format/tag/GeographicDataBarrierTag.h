//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataBarrierTag_h
#define GeographicDataBarrierTag_h
// stream
#include "GeographicDataBaseTag.h"
#include "GeographicDataRecordHeader.h"
class GeographicDataBarrierTag : public GeographicDataBaseTag {
   public:
    unsigned short mapTipType;
    GeographicDataBarrierTag();
    GeographicDataBarrierTag(GeographicNode* node);
    virtual ~GeographicDataBarrierTag();
    void build() override;
};
#endif

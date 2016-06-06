//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GeographicDataRecordHeader_h
#define GeographicDataRecordHeader_h

// stream
#include "GeographicDataBaseFormat.h"

class GeographicDataRecordHeader : public GeographicDataBaseFormat {
   public:
    unsigned char tagType;
    unsigned short geographicId;
    unsigned short parentGeographicId;
    GeographicDataRecordHeader();
    GeographicDataRecordHeader(unsigned char tagType);
    virtual ~GeographicDataRecordHeader();
    GeographicDataRecordHeader* operator=(GeographicDataRecordHeader* format);
};

#endif

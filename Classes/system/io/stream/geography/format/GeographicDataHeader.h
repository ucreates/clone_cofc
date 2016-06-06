//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GeographicDataHeader_h
#define GeographicDataHeader_h

// stream
#include "GeographicDataBaseFormat.h"
#include "GeographicDataRecordHeader.h"

class GeographicDataHeader : public GeographicDataBaseFormat {
   public:
    GeographicDataRecordHeader* header;
    unsigned char signecture[3];
    unsigned char field[3];
    unsigned char version;
    GeographicDataHeader();
    virtual ~GeographicDataHeader();
    void build() override;

   private:
    static const char M = 0x4d;
    static const char A = 0x41;
    static const char P = 0x50;
};

#endif

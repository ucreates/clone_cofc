//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataBaseFormatStream_h
#define GeographicDataBaseFormatStream_h
// stream
#include <iostream>
#include <fstream>
#include "BinaryStream.h"
#include "GeographicDataBaseFormat.h"
#include "GeographicDataRecordHeader.h"
class GeographicDataBaseFormatStream {
   public:
    GeographicDataBaseFormatStream();
    virtual ~GeographicDataBaseFormatStream();
    virtual GeographicDataBaseFormat* read(BinaryStream* stream, GeographicDataRecordHeader* recordHeader);
    virtual GeographicDataBaseFormat* read(BinaryStream* stream);
    virtual bool write(std::ofstream* stream, GeographicDataBaseFormat* format);
};
#endif

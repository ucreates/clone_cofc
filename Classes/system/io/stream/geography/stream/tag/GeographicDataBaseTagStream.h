//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataBaseTagStream_h
#define GeographicDataBaseTagStream_h
// stream
#include "BinaryStream.h"
#include "GeographicDataBaseFormatStream.h"
#include "GeographicDataRecordHeaderStream.h"
class GeographicDataBaseTagStream : public GeographicDataBaseFormatStream {
   public:
    GeographicDataBaseTagStream();
    virtual ~GeographicDataBaseTagStream();
   protected:
    GeographicDataRecordHeaderStream recordHeaderStream;
};
#endif

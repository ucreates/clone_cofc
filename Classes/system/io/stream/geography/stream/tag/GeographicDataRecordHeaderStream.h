//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataRecordHeaderStream_h
#define GeographicDataRecordHeaderStream_h
// stream
#include "BinaryStream.h"
#include "GeographicDataBaseFormatStream.h"
class GeographicDataRecordHeaderStream : public GeographicDataBaseFormatStream {
   public:
    GeographicDataRecordHeaderStream();
    virtual ~GeographicDataRecordHeaderStream();
    GeographicDataBaseFormat* read(BinaryStream* stream) override;
    bool write(std::ofstream* stream, GeographicDataBaseFormat* format) override;
};
#endif

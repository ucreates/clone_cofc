//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GeographicDataHeaderStream_h
#define GeographicDataHeaderStream_h

// stream
#include "GeographicDataBaseFormatStream.h"

class GeographicDataHeaderStream : public GeographicDataBaseFormatStream {
   public:
    GeographicDataHeaderStream();
    virtual ~GeographicDataHeaderStream();
    GeographicDataBaseFormat* read(BinaryStream* stream) override;
    bool write(std::ofstream* stream, GeographicDataBaseFormat* format) override;
};

#endif

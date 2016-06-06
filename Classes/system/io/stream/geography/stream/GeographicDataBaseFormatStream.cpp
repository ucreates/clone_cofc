//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// stream
#include "GeographicDataBaseFormatStream.h"

GeographicDataBaseFormatStream::GeographicDataBaseFormatStream() {}

GeographicDataBaseFormatStream::~GeographicDataBaseFormatStream() {}

GeographicDataBaseFormat* GeographicDataBaseFormatStream::read(BinaryStream* stream, GeographicDataRecordHeader* recordHeader) { return NULL; }

GeographicDataBaseFormat* GeographicDataBaseFormatStream::read(BinaryStream* stream) { return NULL; }

bool GeographicDataBaseFormatStream::write(std::ofstream* stream, GeographicDataBaseFormat* format) { return true; }

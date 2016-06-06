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
#include "GeographicDataFieldTagStream.h"
#include "GeographicDataFieldTag.h"

GeographicDataFieldTagStream::GeographicDataFieldTagStream() {}

GeographicDataFieldTagStream::~GeographicDataFieldTagStream() {}

GeographicDataBaseFormat* GeographicDataFieldTagStream::read(BinaryStream* stream, GeographicDataRecordHeader* recordHeader) {
    GeographicDataFieldTag* tag = new GeographicDataFieldTag();
    tag->header = recordHeader;
    tag->mapTipType = stream->read();
    return tag;
}

bool GeographicDataFieldTagStream::write(std::ofstream* stream, GeographicDataBaseFormat* format) {
    GeographicDataFieldTag* tag = (GeographicDataFieldTag*)format;
    this->recordHeaderStream.write(stream, tag->header);
    stream->write((char*)&tag->mapTipType, sizeof(char));
    return true;
}

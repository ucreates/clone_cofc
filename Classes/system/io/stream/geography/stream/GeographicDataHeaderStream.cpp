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
#include "GeographicDataHeader.h"
#include "GeographicDataHeaderStream.h"

GeographicDataHeaderStream::GeographicDataHeaderStream() {}

GeographicDataHeaderStream::~GeographicDataHeaderStream() {}

GeographicDataBaseFormat* GeographicDataHeaderStream::read(BinaryStream* stream) {
    GeographicDataHeader* tag = new GeographicDataHeader();

    tag->header->tagType = stream->read();

    for (int i = 0; i < 3; i++) {
        tag->signecture[i] = stream->read();
    }

    for (int i = 0; i < 3; i++) {
        tag->field[i] = stream->read();
    }

    tag->version = stream->read();
    return tag;
}

bool GeographicDataHeaderStream::write(std::ofstream* stream, GeographicDataBaseFormat* format) {
    GeographicDataHeader* tag = (GeographicDataHeader*)format;
    stream->write((char*)&tag->header->tagType, sizeof(char));

    for (int i = 0; i < 3; i++) {
        stream->write((char*)&tag->signecture[i], sizeof(char));
    }

    for (int i = 0; i < 3; i++) {
        stream->write((char*)&tag->field[i], sizeof(char));
    }

    stream->write((char*)&tag->version, sizeof(char));
    return true;
}

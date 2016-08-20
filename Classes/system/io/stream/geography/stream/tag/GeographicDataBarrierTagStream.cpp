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
#include "GeographicDataBarrierTagStream.h"
#include "GeographicDataRecordHeaderStream.h"
#include "GeographicDataBarrierTag.h"
#include "GeographicDataRecordHeader.h"
GeographicDataBarrierTagStream::GeographicDataBarrierTagStream() {}
GeographicDataBarrierTagStream::~GeographicDataBarrierTagStream() {}
GeographicDataBaseFormat* GeographicDataBarrierTagStream::read(BinaryStream* stream, GeographicDataRecordHeader* recordHeader) {
    GeographicDataBarrierTag* tag = new GeographicDataBarrierTag();
    tag->header = recordHeader;
    unsigned char upper = stream->read();
    unsigned char downer = stream->read();
    tag->mapTipType = upper << 8 | downer;
    return tag;
}
bool GeographicDataBarrierTagStream::write(std::ofstream* stream, GeographicDataBaseFormat* format) {
    GeographicDataBarrierTag* tag = (GeographicDataBarrierTag*)format;
    this->recordHeaderStream.write(stream, tag->header);
    unsigned char upper = (tag->mapTipType & 0xff00) >> 8;
    stream->write((char*)&upper, sizeof(char));
    unsigned char downer = (tag->mapTipType & 0xff);
    stream->write((char*)&downer, sizeof(char));
    return true;
}

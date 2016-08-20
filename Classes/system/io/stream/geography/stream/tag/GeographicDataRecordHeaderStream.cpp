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
#include "GeographicDataRecordHeaderStream.h"
#include "GeographicDataRecordHeader.h"
GeographicDataRecordHeaderStream::GeographicDataRecordHeaderStream() {}
GeographicDataRecordHeaderStream::~GeographicDataRecordHeaderStream() {}
GeographicDataBaseFormat* GeographicDataRecordHeaderStream::read(BinaryStream* stream) {
    GeographicDataRecordHeader* recordHeader = new GeographicDataRecordHeader();
    recordHeader->tagType = stream->read();
    unsigned char upper = 0x00;
    unsigned char downer = 0x00;
    upper = stream->read();
    downer = stream->read();
    recordHeader->geographicId = upper << 8 | downer;
    upper = stream->read();
    downer = stream->read();
    recordHeader->parentGeographicId = upper << 8 | downer;
    return recordHeader;
}
bool GeographicDataRecordHeaderStream::write(std::ofstream* stream, GeographicDataBaseFormat* format) {
    GeographicDataRecordHeader* recordHeader = (GeographicDataRecordHeader*)format;
    stream->write((char*)&recordHeader->tagType, sizeof(char));
    unsigned char upper = 0x00;
    unsigned char downer = 0x00;
    upper = (recordHeader->geographicId & 0xff00) >> 8;
    stream->write((char*)&upper, sizeof(char));
    downer = (recordHeader->geographicId & 0x00ff);
    stream->write((char*)&downer, sizeof(char));
    upper = (recordHeader->parentGeographicId & 0xff00) >> 8;
    stream->write((char*)&upper, sizeof(char));
    downer = (recordHeader->parentGeographicId & 0x00ff);
    stream->write((char*)&downer, sizeof(char));
    return true;
}

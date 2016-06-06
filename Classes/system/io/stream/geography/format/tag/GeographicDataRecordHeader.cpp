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
#include "GeographicDataRecordHeader.h"

GeographicDataRecordHeader::GeographicDataRecordHeader() { this->tagType = 0xff; }

GeographicDataRecordHeader::GeographicDataRecordHeader(unsigned char tagType) {
    this->tagType = tagType;
    this->geographicId = 0;
    this->parentGeographicId = 0;
}

GeographicDataRecordHeader::~GeographicDataRecordHeader() {}

GeographicDataRecordHeader* GeographicDataRecordHeader::operator=(GeographicDataRecordHeader* format) {
    this->tagType = format->tagType;
    this->geographicId = format->geographicId;
    this->parentGeographicId = format->parentGeographicId;
    return this;
}
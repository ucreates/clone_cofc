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
// geographic
#include "GeographicGateway.h"
GeographicDataHeader::GeographicDataHeader() { this->header = new GeographicDataRecordHeader(0x00); }
GeographicDataHeader::~GeographicDataHeader() { CC_SAFE_DELETE(this->header); }
void GeographicDataHeader::build() {
    this->signecture[0] = GeographicDataHeader::M;
    this->signecture[1] = GeographicDataHeader::A;
    this->signecture[2] = GeographicDataHeader::P;
    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicSize* size = gateway->getSize();
    this->field[0] = size->worldAddress.x & 0xff;
    this->field[1] = size->worldAddress.y & 0xff;
    this->field[2] = size->worldAddress.z & 0xff;
    this->version = 0x01;
}

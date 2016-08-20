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
#include "GeographicDataFieldTag.h"
GeographicDataFieldTag::GeographicDataFieldTag() {}
GeographicDataFieldTag::GeographicDataFieldTag(GeographicNode* node) {
    this->header = new GeographicDataRecordHeader(GeographicDataBaseFormat::FIELD);
    this->header->geographicId = node->geographicId;
    this->header->parentGeographicId = node->parentGeographicId;
    this->node = node;
}
GeographicDataFieldTag::~GeographicDataFieldTag() {}
void GeographicDataFieldTag::build() { this->mapTipType = (this->node->type & 0xff); }
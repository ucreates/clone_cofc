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
#include "GeographicDataBarrierTag.h"
GeographicDataBarrierTag::GeographicDataBarrierTag() {}
GeographicDataBarrierTag::GeographicDataBarrierTag(GeographicNode* node) {
    this->header = new GeographicDataRecordHeader(GeographicDataBaseFormat::BARRIER);
    this->header->geographicId = node->geographicId;
    this->header->parentGeographicId = node->parentGeographicId;
    this->node = node;
}
GeographicDataBarrierTag::~GeographicDataBarrierTag() {}
void GeographicDataBarrierTag::build() { this->mapTipType = this->node->type; }
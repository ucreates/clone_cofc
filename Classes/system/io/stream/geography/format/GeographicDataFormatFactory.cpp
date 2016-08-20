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
#include "GeographicDataFormatFactory.h"
#include "GeographicDataHeader.h"
#include "GeographicDataFieldTag.h"
#include "GeographicDataBarrierTag.h"
GeographicDataBaseFormat* GeographicDataFormatFactory::factoryMethod(unsigned char formatType, GeographicNode* node) {
    GeographicDataBaseFormat* format = NULL;
    switch (formatType) {
        case GeographicDataBaseFormat::HEADER:
            format = new GeographicDataHeader();
            break;
        case GeographicDataBaseFormat::FIELD:
            format = new GeographicDataFieldTag(node);
            break;
        case GeographicDataBaseFormat::BARRIER:
            format = new GeographicDataBarrierTag(node);
            break;
        default:
            break;
    }
    if (NULL != format) {
        format->build();
    }
    return format;
}
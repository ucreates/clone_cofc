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
#include "GeographicDataSreamFactory.h"
#include "GeographicDataHeaderStream.h"
#include "GeographicDataFieldTagStream.h"
#include "GeographicDataBarrierTagStream.h"
GeographicDataBaseFormatStream* GeographicDataSreamFactory::factoryMethod(unsigned char formatType) {
    GeographicDataBaseFormatStream* stream = NULL;
    switch (formatType) {
        case GeographicDataBaseFormat::HEADER:
            stream = new GeographicDataHeaderStream();
            break;
        case GeographicDataBaseFormat::FIELD:
            stream = new GeographicDataFieldTagStream();
            break;
        case GeographicDataBaseFormat::BARRIER:
            stream = new GeographicDataBarrierTagStream();
            break;
        default:
            break;
    }
    return stream;
}
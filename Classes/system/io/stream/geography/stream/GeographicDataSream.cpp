//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// stl
#include <fstream>
#include <vector>

// stream
#include "BinaryStream.h"
#include "GeographicGateway.h"
#include "GeographicDataFormatFactory.h"
#include "GeographicDataSreamFactory.h"
#include "GeographicDataStream.h"
#include "GeographicDataBaseFormatStream.h"
#include "GeographicDataRecordHeaderStream.h"
#include "GeographicDataHeader.h"
#include "GeographicDataFieldTag.h"
#include "GeographicDataBarrierTag.h"

using namespace cocos2d;

GeographicDataStream::GeographicDataStream() {}

GeographicDataStream::~GeographicDataStream() {}

std::map<int, GeographicDataBaseTag*> GeographicDataStream::read(std::string filePath) {
    std::map<int, GeographicDataBaseTag*> dataFormatMap;
    std::string fileExt = strstr(filePath.c_str(), ".");
    if (".map" != fileExt) {
        return dataFormatMap;
    }
    BinaryStream* binaryStream = new BinaryStream(filePath);
    if (false == binaryStream->isValid()) {
        CC_SAFE_DELETE(binaryStream);
        return dataFormatMap;
    }

    GeographicDataBaseFormatStream* stream = GeographicDataSreamFactory::factoryMethod(GeographicDataBaseFormat::HEADER);
    GeographicDataHeader* header = (GeographicDataHeader*)stream->read(binaryStream);

    if (NULL == header || 'M' != header->signecture[0] || 'A' != header->signecture[1] || 'P' != header->signecture[2]) {
        return dataFormatMap;
    }
    CC_SAFE_DELETE(stream);
    CC_SAFE_DELETE(header);

    GeographicDataRecordHeaderStream* headerStream = new GeographicDataRecordHeaderStream();
    while (false == binaryStream->isEOF()) {
        GeographicDataRecordHeader* recordHeader = (GeographicDataRecordHeader*)headerStream->read(binaryStream);
        stream = GeographicDataSreamFactory::factoryMethod(recordHeader->tagType);
        if (NULL != stream) {
            GeographicDataBaseTag* format = (GeographicDataBaseTag*)stream->read(binaryStream, recordHeader);
            dataFormatMap.insert(std::map<int, GeographicDataBaseTag*>::value_type(format->header->geographicId, format));
        }
        delete stream;
    }
    CC_SAFE_DELETE(headerStream);
    CC_SAFE_DELETE(binaryStream);
    return dataFormatMap;
}

bool GeographicDataStream::write(std::string filePath) {
    std::string fileExt = strstr(filePath.c_str(), ".");
    if (".map" != fileExt) {
        return false;
    }

    std::ofstream* ofs = new std::ofstream();
    ofs->open(filePath, std::ios::out | std::ios::binary | std::ios::trunc);
    if (NULL == ofs) {
        return false;
    }

    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicSize* size = gateway->getSize();

    GeographicDataBaseFormat* format = GeographicDataFormatFactory::factoryMethod(GeographicDataBaseFormat::HEADER, NULL);
    GeographicDataBaseFormatStream* stream = GeographicDataSreamFactory::factoryMethod(GeographicDataBaseFormat::HEADER);
    stream->write(ofs, format);
    CC_SAFE_DELETE(format);
    CC_SAFE_DELETE(stream);

    for (int wz = 0; wz < size->worldAddress.z; wz++) {
        for (int wy = 0; wy < size->worldAddress.y; wy++) {
            for (int wx = 0; wx < size->worldAddress.x; wx++) {
                GeographicNode* node = gateway->findByAddress(wx, wy, wz);
                unsigned char barrierType = (node->type & 0xff00) >> 8;

                unsigned char formatType = 0x00;
                if (0x00 == barrierType) {
                    formatType = 0x01;
                } else {
                    formatType = 0x02;
                }
                format = GeographicDataFormatFactory::factoryMethod(formatType, node);
                stream = GeographicDataSreamFactory::factoryMethod(formatType);
                stream->write(ofs, format);
                CC_SAFE_DELETE(format);
                CC_SAFE_DELETE(stream);
            }
        }
    }
    ofs->close();
    CC_SAFE_DELETE(ofs);
    return true;
}
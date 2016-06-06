//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// standard
#include <stdio.h>
#include <string.h>

// stl
#include <fstream>

// cocos2d
#include "cocos2d.h"

// stream
#include "BinaryStream.h"

using namespace cocos2d;

BinaryStream::BinaryStream() {
    this->fileSize = 0;
    this->streamData = NULL;
}

BinaryStream::BinaryStream(std::string filePath) {
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filePath);
    Data data = FileUtils::getInstance()->getDataFromFile(fullpath.c_str());
    this->fileSize = data.getSize();
    this->streamData = new unsigned char[this->fileSize];
    memcpy(this->streamData, data.getBytes(), this->fileSize);
}

BinaryStream::~BinaryStream() {
    this->streamData -= this->fileSize;
    delete[] this->streamData;
}

unsigned char BinaryStream::read() {
    unsigned char byte = *this->streamData & 0xff;
    if (this->seek == this->fileSize) {
        this->eof = true;
        return 0xff;
    }
    this->streamData++;
    this->seek++;
    return byte;
}

bool BinaryStream::write(std::string filePath, std::vector<char>* dataVector) {
    std::ofstream ofs;
    ofs.open(filePath.c_str(), std::ios::out | std::ios::trunc);
    ofs.write(&(dataVector->front()), dataVector->size());
    ofs.flush();
    ofs.close();
    return true;
}

bool BinaryStream::isValid() {
    if (NULL == this->streamData) {
        return false;
    }
    return true;
}
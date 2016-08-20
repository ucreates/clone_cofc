//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BinaryStream_h
#define BinaryStream_h
// stl
#include <string>
// stream
#include "BaseStream.h"
class BinaryStream : public BaseStream {
   public:
    BinaryStream();
    BinaryStream(std::string filePath);
    ~BinaryStream();
    unsigned char read() override;
    bool write(std::string filePath, std::vector<char>* dataVector) override;
    bool isValid() override;
   private:
    unsigned char* streamData;
};
#endif

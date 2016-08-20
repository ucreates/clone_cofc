//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseStream_h
#define BaseStream_h
// stl
#include <string>
#include <vector>
class BaseStream {
   public:
    BaseStream();
    ~BaseStream();
    virtual unsigned char read();
    virtual bool write(std::string filePath, std::vector<char>* dataVector);
    virtual bool isValid();
    bool isEOF();
   protected:
    int seek;
    int fileSize;
    bool eof;
};
#endif

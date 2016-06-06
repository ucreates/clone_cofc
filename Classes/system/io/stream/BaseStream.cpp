//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BaseStream.h"

BaseStream::BaseStream() : eof(false), seek(0) {}

BaseStream::~BaseStream() {}

unsigned char BaseStream::read() {}

bool BaseStream::write(std::string filePath, std::vector<char>* dataVector) { return true; }

bool BaseStream::isValid() { return true; }

bool BaseStream::isEOF() { return this->eof; }

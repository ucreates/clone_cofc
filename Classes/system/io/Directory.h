//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Directory_h
#define Directory_h
#include <string>
class Directory {
   public:
    static bool create(std::string dirname);
    static std::string getDirectoryName(std::string filePath);
};
#endif
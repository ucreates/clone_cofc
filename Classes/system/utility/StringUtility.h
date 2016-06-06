//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef StringUtility_h
#define StringUtility_h

// stl
#include <list>
#include <string>

class StringUtility {
   public:
    static std::vector<std::string> split(std::string string, std::string delimitter);
    static std::string replace(std::string source, std::string needle, std::string value);
    static std::string replace(std::string source, std::list<std::string> needleList, std::string value);
};

#endif
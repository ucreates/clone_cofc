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
#include <vector>

// utility
#include "StringUtility.h"

std::vector<std::string> StringUtility::split(std::string src, std::string delim) {
    std::vector<std::string> ret;
    std::string::size_type start = 0;
    while (true) {
        std::string::size_type end = src.find(delim, start);
        if (end != std::string::npos) {
            ret.push_back(src.substr(start, end - start));
        } else {
            ret.push_back(src.substr(start, src.length() - start));
            break;
        }
        start = end + delim.length();
    }
    return ret;
}

std::string StringUtility::replace(std::string source, std::string needle, std::string value) {
    std::string::size_type pos(source.find(needle));

    while (pos != std::string::npos) {
        source.replace(pos, needle.length(), value);
        pos = source.find(needle, pos + value.length());
    }

    return source;
}

std::string StringUtility::replace(std::string source, std::list<std::string> needleList, std::string value) {
    std::string tmpSource = source;
    for (std::list<std::string>::iterator it = needleList.begin(); it != needleList.end(); it++) {
        tmpSource = StringUtility::replace(tmpSource, (*it), value);
    }
    return tmpSource;
}

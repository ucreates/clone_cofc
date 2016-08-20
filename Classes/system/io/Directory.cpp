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
#include <sys/stat.h>
// cocos2d
#include "cocos2d.h"
// stl
#include <vector>
// utility
#include "StringUtility.h"
// io
#include "Directory.h"
using namespace cocos2d;
bool Directory::create(std::string dirname) {
    FileUtils* fileUtils = FileUtils::getInstance();
    std::vector<std::string> dirVector = StringUtility::split(dirname, "/");
    std::string filepath;
    for (int i = 0; i < dirVector.size(); i++) {
        filepath += dirVector.at(i).c_str();
        filepath += "/";
        if (!fileUtils->isFileExist(filepath)) {
            mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR | S_IROTH | S_IWOTH | S_IXOTH;
            int ret = mkdir(filepath.c_str(), mode);
            if (0 != ret) {
                CCLOGERROR("can not create directory");
                return false;
            }
        }
    }
    return true;
}
std::string Directory::getDirectoryName(std::string filePath) {
    int dirIndex = filePath.find_last_of("/");
    std::string dirname = filePath.substr(0, dirIndex);
    return dirname;
}

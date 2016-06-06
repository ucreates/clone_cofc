//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef KeySchema_h
#define KeySchema_h

// stl
#include <map>
#include <string>

class KeySchema {
   public:
    std::string get();
    std::string get(std::string fieldName);
    int getId();
    std::map<std::string, std::string> getKeyHolder();
    bool set(std::string fieldName, std::string fieldValue);
    bool set(std::string fieldName, int fieldValue);
    bool operator==(KeySchema &key);

   private:
    std::string key;
    std::map<std::string, std::string> keyHolderMap;
};

#endif

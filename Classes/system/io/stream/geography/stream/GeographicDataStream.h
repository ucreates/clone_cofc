//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GeographicDataStream_h
#define GeographicDataStream_h

// stl
#include <map>

// stream
#include "GeographicDataBaseTag.h"

class GeographicDataStream {
   public:
    GeographicDataStream();
    virtual ~GeographicDataStream();
    std::map<int, GeographicDataBaseTag*> read(std::string filePath);
    bool write(std::string filePath);
};

#endif

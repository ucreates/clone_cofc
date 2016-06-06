//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TRouteTable_h
#define TRouteTable_h

// geographic
#include "GeographicNode.h"

// service
#include "BaseTable.h"

class TRouteTable : public BaseTable {
   public:
    unsigned int startGeographicId;
    unsigned int goalGeographicId;
    std::vector<GeographicNode*> routeCacheVector;
    TRouteTable();
    void build() override;
};

#endif

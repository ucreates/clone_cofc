//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TOverAllTable_h
#define TOverAllTable_h

// service
#include "BaseTable.h"

class TOverAllTable : public BaseTable {
   public:
    int current;
    int total;
    bool reachedLevel1;
    bool reachedLevel2;
    bool reachedLevel3;
    TOverAllTable();
    void build() override;
};

#endif

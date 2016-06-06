//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef MBarrierTable_h
#define MBarrierTable_h

// service
#include "BaseTable.h"

class MBarrierTable : public BaseTable {
   public:
    int type;
    std::string name;
    int hp;
    int power;
    MBarrierTable();
    void build() override;
};

#endif

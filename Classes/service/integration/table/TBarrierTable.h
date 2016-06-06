//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TBarrierTable_h
#define TBarrierTable_h
// service
#include "BaseTable.h"

class TBarrierTable : public BaseTable {
   public:
    int barrierId;
    int type;
    int hp;
    int power;
    TBarrierTable();
    void build() override;
};

#endif

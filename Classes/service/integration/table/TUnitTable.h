//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TUnitTable_h
#define TUnitTable_h
// service
#include "BaseTable.h"
struct TUnitTable : public BaseTable {
   public:
    int unitId;
    int type;
    int hp;
    int power;
    TUnitTable();
    void build() override;
};
#endif

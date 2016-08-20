//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef MResourceTable_h
#define MResourceTable_h
// service
#include "BaseTable.h"
class MResourceTable : public BaseTable {
   public:
    int emerald;
    int gold;
    int elixir;
    MResourceTable();
    void build() override;
};
#endif

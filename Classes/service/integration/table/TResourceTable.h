//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TResourceTable_h
#define TResourceTable_h

// service
#include "BaseTable.h"

class TResourceTable : public BaseTable {
   public:
    bool isEnemy;
    int gold;
    int elixir;
    int emerald;
    int archer;
    int barbarian;
    int giant;
    int goblin;
    int wallbreaker;
    int selectUnitType;
    TResourceTable();
    void build() override;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TDownLoadTable_h
#define TDownLoadTable_h
// service
#include "BaseTable.h"
class TDownLoadTable : public BaseTable {
   public:
    bool emitDownLoad;
    int current;
    int total;
    bool isAssetCache;
    TDownLoadTable();
    void build() override;
};
#endif

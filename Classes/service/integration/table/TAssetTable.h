//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TAssetTable_h
#define TAssetTable_h
// service
#include "BaseTable.h"
struct TAssetTable : public BaseTable {
   public:
    std::string name;
    std::string type;
    std::string path;
    TAssetTable();
    void build() override;
};
#endif

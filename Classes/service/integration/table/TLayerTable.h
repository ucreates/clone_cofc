//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TLayerTable_h
#define TLayerTable_h

// cocos2d
#include "cocos2d.h"

// debug
#include "Macro.h"

// service
#include "BaseTable.h"

class TLayerTable : public BaseTable {
   public:
    cocos2d::Layer* layer;
    int layerId;
    TLayerTable();
    void build() override;
};
#endif

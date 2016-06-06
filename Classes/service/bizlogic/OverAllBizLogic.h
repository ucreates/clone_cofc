//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef OverAllBizLogic_h
#define OverAllBizLogic_h

// service
#include "BaseBizLogic.h"
#include "TOverAllTable.h"

class OverAllBizLogic : public BaseBizLogic {
   public:
    OverAllBizLogic();
    TOverAllTable getOverAll();
    void saveOverAll(int currentOverAll, int toalOverAll);
    bool AddCurrentOverAll();
    bool isOverAll();
    bool updateOverAll(int overAllLevel);
    float getCurrentPercent();
    void clear() override;

   private:
    static const int OVER_ALL_LEVEL1 = 1;
    static const int OVER_ALL_LEVEL2 = 2;
    static const int OVER_ALL_LEVEL3 = 3;
};

#endif
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef UnitBizLogic_h
#define UnitBizLogic_h

// service
#include "BaseBizLogic.h"
#include "MUnitTable.h"
#include "TUnitTable.h"

class UnitBizLogic : public BaseBizLogic {
   public:
    UnitBizLogic();
    void create();
    TUnitTable findByUnitId(int unitId);
    bool addUnitMaster(int type, std::string name, int hp, int power);
    bool addUnit(int id, int type);
    MUnitTable findMasterByType(int type);
    int addDamage(int unitId, int point);
    int getHp(int id);
    float getHpPercent(int id);
    void clear() override;
};

#endif
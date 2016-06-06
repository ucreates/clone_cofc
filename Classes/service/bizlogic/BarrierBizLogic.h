//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BarrierBizLogic_h
#define BarrierBizLogic_h

// stl
#include <vector>

// service
#include "BaseBizLogic.h"
#include "TBarrierTable.h"
#include "MBarrierTable.h"

class BarrierBizLogic : public BaseBizLogic {
   public:
    BarrierBizLogic();
    TBarrierTable findByBarrierId(int barrierId);
    bool addBarrier(int id, int type);
    MBarrierTable findMasterByType(int type);
    void create();
    bool addBarrierMaster(int type, std::string name, int hp, int power);
    int addDamage(int id, int point);
    int getHp(int id);
    float getHpPercent(int id);
    bool destroy(int id);
    bool destroy(std::vector<int> destroyIdVector);
    void clear() override;
};

#endif
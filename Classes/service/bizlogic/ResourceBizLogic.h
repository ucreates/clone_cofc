//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ResourceBizLogic_h
#define ResourceBizLogic_h

// service
#include "BaseBizLogic.h"
#include "MResourceTable.h"
#include "TResourceTable.h"

class ResourceBizLogic : public BaseBizLogic {
   public:
    static const int RESOURCE_EMERALD = 1;
    static const int RESOURCE_ELIXIR = 2;
    static const int RESOURCE_GOLD = 3;
    ResourceBizLogic();
    void create();
    bool selectUnit(int unitId);
    bool updateUnit(int unitId, int number = 1);
    bool updateGold(bool isEnemy);
    bool updateElixir(bool isEnemy);
    bool updateEmerald(bool isEnemy);
    int getEnemyResourceCount(int resourceId);
    float getPlayerResourcePercent(int resourceId);
    TResourceTable getPlayerResourceInfo();
    MResourceTable getMaxResourceInfo();
    void clear() override;

   private:
    static const int RESOURCE_EMERALD_UNIT = 10;
    static const int RESOURCE_ELIXIR_UNIT = 100;
    static const int RESOURCE_GOLD_UNIT = 100;
};

#endif
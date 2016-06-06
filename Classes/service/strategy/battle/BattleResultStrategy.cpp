//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// service
#include "BattleResultStrategy.h"
#include "ResourceBizLogic.h"
#include "OverAllBizLogic.h"
#include "TResourceTable.h"

BattleResultStrategy::BattleResultStrategy() {}

BattleResultStrategy::~BattleResultStrategy() {}

Response BattleResultStrategy::get(Parameter* parameter) {
    ResourceBizLogic resrouceBizLogic;
    float enemyEmeraldRate = resrouceBizLogic.getPlayerResourcePercent(1);
    float enemyElixirRate = resrouceBizLogic.getPlayerResourcePercent(2);
    float enemyGoldRate = resrouceBizLogic.getPlayerResourcePercent(3);

    TResourceTable record = resrouceBizLogic.getPlayerResourceInfo();
    int playerElixirCount = record.elixir;
    int playerGoldCount = record.gold;
    int playerEmeraldCount = record.emerald;

    int playerArcherCount = record.archer;
    int playerBarbarianCount = record.barbarian;
    int playerGiantCount = record.giant;
    int playerGoblinCount = record.goblin;
    int playerWallBreakerCount = record.wallbreaker;

    OverAllBizLogic overAllBizLogic;
    int overAllRate = overAllBizLogic.getCurrentPercent();

    Response res;
    res.set<int>("playerElixirCount", playerElixirCount);
    res.set<int>("playerGoldCount", playerGoldCount);
    res.set<int>("playerEmeraldCount", playerEmeraldCount);
    res.set<float>("enemyEmeraldRate", enemyEmeraldRate);
    res.set<float>("enemyElixirRate", enemyElixirRate);
    res.set<float>("enemyGoldRate", enemyGoldRate);

    res.set<int>("playerArcherCount", playerArcherCount);
    res.set<int>("playerBarbarianCount", playerBarbarianCount);
    res.set<int>("playerGiantCount", playerGiantCount);
    res.set<int>("playerGoblinCount", playerGoblinCount);
    res.set<int>("playerWallBreakerCount", playerWallBreakerCount);

    res.set<int>("overAllRate", overAllRate);
    return res;
}
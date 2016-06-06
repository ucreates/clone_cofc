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
#include "ResourceInfoStrategy.h"
#include "ResourceBizLogic.h"
#include "MResourceTable.h"
#include "TResourceTable.h"

ResourceInfoStrategy::ResourceInfoStrategy() {}

ResourceInfoStrategy::~ResourceInfoStrategy() {}

Response ResourceInfoStrategy::get(Parameter* parameter) {
    ResourceBizLogic resrouceBizLogic;
    int enemyElixirCount = resrouceBizLogic.getEnemyResourceCount(2);
    int enemyGoldCount = resrouceBizLogic.getEnemyResourceCount(3);

    float playerElixirRate = resrouceBizLogic.getPlayerResourcePercent(ResourceBizLogic::RESOURCE_ELIXIR);
    float playerGoldRate = resrouceBizLogic.getPlayerResourcePercent(ResourceBizLogic::RESOURCE_GOLD);
    float playerEmeraldRate = resrouceBizLogic.getPlayerResourcePercent(ResourceBizLogic::RESOURCE_EMERALD);

    TResourceTable record = resrouceBizLogic.getPlayerResourceInfo();
    int playerElixirCount = record.elixir;
    int playerGoldCount = record.gold;
    int playerEmeraldCount = record.emerald;

    int playerArcherCount = record.archer;
    int playerBarbarianCount = record.barbarian;
    int playerGiantCount = record.giant;
    int playerGoblinCount = record.goblin;
    int playerWallBreakerCount = record.wallbreaker;

    MResourceTable mrecord = resrouceBizLogic.getMaxResourceInfo();
    int maxElixirCount = mrecord.elixir;
    int maxGoldCount = mrecord.gold;

    Response res;
    res.set<int>("maxElixirCount", maxElixirCount);
    res.set<int>("maxGoldCount", maxGoldCount);

    res.set<int>("playerElixirCount", playerElixirCount);
    res.set<int>("playerGoldCount", playerGoldCount);
    res.set<int>("playerEmeraldCount", playerEmeraldCount);
    res.set<int>("enemyElixirCount", enemyElixirCount);
    res.set<int>("enemyGoldCount", enemyGoldCount);

    res.set<float>("playerElixirRate", playerElixirRate);
    res.set<float>("playerGoldRate", playerGoldRate);
    res.set<float>("playerEmeraldRate", playerEmeraldRate);

    res.set<int>("playerArcherCount", playerArcherCount);
    res.set<int>("playerBarbarianCount", playerBarbarianCount);
    res.set<int>("playerGiantCount", playerGiantCount);
    res.set<int>("playerGoblinCount", playerGoblinCount);
    res.set<int>("playerWallBreakerCount", playerWallBreakerCount);

    return res;
}
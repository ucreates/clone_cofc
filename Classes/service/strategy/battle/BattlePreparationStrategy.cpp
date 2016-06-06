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
#include "BattlePreparationStrategy.h"
#include "OverAllBizLogic.h"
#include "ResourceBizLogic.h"

BattlePreparationStrategy::BattlePreparationStrategy() {}

BattlePreparationStrategy::~BattlePreparationStrategy() {}

Response BattlePreparationStrategy::get(Parameter* parameter) {
    OverAllBizLogic overAllBizLogic;
    bool isOverAll = overAllBizLogic.isOverAll();
    Response res;
    res.set<bool>("isOverAll", isOverAll);
    return res;
}

Response BattlePreparationStrategy::update(Parameter* parameter) {
    int barrierCount = parameter->get<int>("barrierCount");
    OverAllBizLogic overAllBizLogic;
    overAllBizLogic.saveOverAll(0.0f, barrierCount);

    ResourceBizLogic resourceBizLogic;
    resourceBizLogic.create();
    TResourceTable record = resourceBizLogic.getPlayerResourceInfo();
    std::map<std::string, int> unitResourceMap;
    unitResourceMap.insert(std::map<std::string, int>::value_type("archer", record.archer));
    unitResourceMap.insert(std::map<std::string, int>::value_type("barbarian", record.barbarian));
    unitResourceMap.insert(std::map<std::string, int>::value_type("giant", record.giant));
    unitResourceMap.insert(std::map<std::string, int>::value_type("goblin", record.goblin));
    unitResourceMap.insert(std::map<std::string, int>::value_type("wallbreaker", record.wallbreaker));

    Response res;
    res.set<std::map<std::string, int>>("unitResourceMap", unitResourceMap);
    return res;
}
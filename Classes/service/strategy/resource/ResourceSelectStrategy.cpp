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
#include "ResourceSelectStrategy.h"
#include "ResourceBizLogic.h"
#include "UnitBizLogic.h"
#include "UnitBehaviourType.h"
ResourceSelectStrategy::ResourceSelectStrategy() {}
ResourceSelectStrategy::~ResourceSelectStrategy() {}
Response ResourceSelectStrategy::get(Parameter* parameter) {
    Response res;
    ResourceBizLogic resourceBizLogic;
    TResourceTable record = resourceBizLogic.getPlayerResourceInfo();
    if (0 == record.selectUnitType) {
        res.setStatus(ServiceStatus::FAILD);
        return res;
    }
    res.set<int>("selectUnitId", record.selectUnitType);
    UnitBizLogic unitBizLogic;
    MUnitTable unitMaster = unitBizLogic.findMasterByType(record.selectUnitType);
    res.set<std::string>("selectUnitType", unitMaster.name);
    int count = 0;
    if (UnitBehaviourType::Archer == record.selectUnitType) {
        count = record.archer;
    } else if (UnitBehaviourType::Barbarian == record.selectUnitType) {
        count = record.barbarian;
    } else if (UnitBehaviourType::Giant == record.selectUnitType) {
        count = record.giant;
    } else if (UnitBehaviourType::Goblin == record.selectUnitType) {
        count = record.goblin;
    } else if (UnitBehaviourType::WallBreaker == record.selectUnitType) {
        count = record.wallbreaker;
    }
    res.set<int>("selectUnitCount", count);
    resourceBizLogic.updateUnit(record.selectUnitType);
    return res;
}
Response ResourceSelectStrategy::update(Parameter* parameter) {
    int id = parameter->get<int>("unitId");
    ResourceBizLogic resrouce;
    resrouce.selectUnit(id);
    Response res;
    return res;
}
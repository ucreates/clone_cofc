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
#include "UnitDamageStrategy.h"
#include "BarrierBizLogic.h"
#include "UnitBizLogic.h"
#include "TBarrierTable.h"
UnitDamageStrategy::UnitDamageStrategy() {}
UnitDamageStrategy::~UnitDamageStrategy() {}
Response UnitDamageStrategy::get(Parameter* parameter) {
    int unitId = parameter->get<int>("unitId");
    UnitBizLogic unitBizLogic;
    int restHp = unitBizLogic.getHp(unitId);
    float percentage = unitBizLogic.getHpPercent(unitId);
    Response res;
    res.set<int>("restHp", restHp);
    res.set<float>("restHpPercentage", percentage);
    return res;
}
Response UnitDamageStrategy::update(Parameter* parameter) {
    int unitId = parameter->get<int>("unitId");
    int barrierId = parameter->get<int>("barrierId");
    BarrierBizLogic barrierBizLogic;
    TBarrierTable barrier = barrierBizLogic.findByBarrierId(barrierId);
    int damage = barrier.power;
    UnitBizLogic unit;
    int restHp = unit.addDamage(unitId, damage);
    Response res;
    res.set<int>("restHp", restHp);
    return res;
}
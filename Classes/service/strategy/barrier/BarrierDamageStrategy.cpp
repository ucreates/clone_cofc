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
#include "BarrierDamageStrategy.h"
#include "UnitBizLogic.h"
#include "BarrierBizLogic.h"

BarrierDamageStrategy::BarrierDamageStrategy() {}

BarrierDamageStrategy::~BarrierDamageStrategy() {}

Response BarrierDamageStrategy::get(Parameter* parameter) {
    int barrierId = parameter->get<int>("barrierId");
    BarrierBizLogic barrierBizLogic;
    int hp = barrierBizLogic.getHp(barrierId);
    float percentage = barrierBizLogic.getHpPercent(barrierId);
    Response res;
    res.set<int>("restHp", hp);
    res.set<float>("restHpPercentage", percentage);
    if (hp < 0 || percentage < 0.0f) {
        res.setStatus(ServiceStatus::FAILD);
    }

    return res;
}

Response BarrierDamageStrategy::update(Parameter* parameter) {
    int barrierId = parameter->get<int>("barrierId");
    int unitId = parameter->get<int>("unitId");

    UnitBizLogic unitBizLogic;
    TUnitTable unit = unitBizLogic.findByUnitId(unitId);
    int damage = unit.power;

    BarrierBizLogic barrierBizLogic;
    int restHp = barrierBizLogic.addDamage(barrierId, damage);
    float percentage = barrierBizLogic.getHpPercent(barrierId);
    Response res;
    res.set<int>("restHp", restHp);
    res.set<float>("restHpPercentage", percentage);
    if (restHp < 0) {
        res.setStatus(ServiceStatus::FAILD);
    }
    return res;
}
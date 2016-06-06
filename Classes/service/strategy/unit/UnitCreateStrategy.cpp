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
#include "UnitCreateStrategy.h"
#include "UnitBizLogic.h"
#include "AssetBizLogic.h"

UnitCreateStrategy::UnitCreateStrategy() {}

UnitCreateStrategy::~UnitCreateStrategy() {}

Response UnitCreateStrategy::update(Parameter* parameter) {
    int unitId = parameter->get<int>("unitId");
    int unitType = parameter->get<int>("unitType");
    UnitBizLogic unitBizLogic;
    bool ret = unitBizLogic.addUnit(unitId, unitType);
    Response res;
    if (false == ret) {
        res.setStatus(ServiceStatus::FAILD);
    }
    return res;
}
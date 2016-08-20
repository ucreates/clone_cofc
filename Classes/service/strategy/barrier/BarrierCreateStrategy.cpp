//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BarrierCreateStrategy.h"
#include "BarrierBizLogic.h"
BarrierCreateStrategy::BarrierCreateStrategy() {}
BarrierCreateStrategy::~BarrierCreateStrategy() {}
Response BarrierCreateStrategy::update(Parameter* parameter) {
    int barrierId = parameter->get<int>("barrierId");
    int barrierType = parameter->get<int>("barrierType");
    BarrierBizLogic barrierBizLogic;
    bool ret = barrierBizLogic.addBarrier(barrierId, barrierType);
    Response res;
    if (false == ret) {
        res.setStatus(ServiceStatus::FAILD);
    }
    return res;
}
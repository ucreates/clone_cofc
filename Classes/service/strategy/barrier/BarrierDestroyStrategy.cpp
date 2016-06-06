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
#include "BarrierDestroyStrategy.h"
#include "BarrierBizLogic.h"
#include "OverAllBizLogic.h"
#include "ResourceBizLogic.h"

BarrierDestroyStrategy::BarrierDestroyStrategy() {}

BarrierDestroyStrategy::~BarrierDestroyStrategy() {}

Response BarrierDestroyStrategy::update(Parameter* parameter) {
    Response res;

    std::string barrierName = parameter->get<std::string>("barrierName");
    OverAllBizLogic overallBizLogic;
    if ("woodFenceH" != barrierName && "woodFenceV" != barrierName) {
        int id = parameter->get<int>("id");
        BarrierBizLogic barrierBizLogic;
        bool ret = barrierBizLogic.destroy(id);
        if (false != ret) {
            bool ret = overallBizLogic.AddCurrentOverAll();
            if (false == ret) {
                res.setStatus(ServiceStatus::FAILD);
                return res;
            }
        }
    }

    bool ret = false;
    ResourceBizLogic resourceBizLogic;
    if ("goldStrage" == barrierName) {
        ret = resourceBizLogic.updateGold(true);
        ret = resourceBizLogic.updateGold(false);
    } else if ("elixirTank" == barrierName) {
        ret = resourceBizLogic.updateElixir(true);
        ret = resourceBizLogic.updateElixir(false);
    } else if ("cannon" == barrierName || "mortar" == barrierName || "turret" == barrierName) {
        ret = resourceBizLogic.updateEmerald(true);
        ret = resourceBizLogic.updateEmerald(false);
    } else {
        ret = true;
    }

    if (false == ret) {
        res.setStatus(ServiceStatus::FAILD);
        return res;
    }

    TOverAllTable record = overallBizLogic.getOverAll();
    res.set<TOverAllTable>("overAll", record);

    bool showOverAllStar = false;
    float overAllRate = overallBizLogic.getCurrentPercent();
    if (50.0f < overAllRate && false == record.reachedLevel1) {
        ret = overallBizLogic.updateOverAll(1);
        showOverAllStar = true;
    } else if (75.0f < overAllRate && false == record.reachedLevel2) {
        ret = overallBizLogic.updateOverAll(2);
        showOverAllStar = true;
    } else if (100.0f <= overAllRate && false == record.reachedLevel3) {
        ret = overallBizLogic.updateOverAll(3);
        showOverAllStar = true;
    }

    if (false == ret) {
        res.setStatus(ServiceStatus::FAILD);
        return res;
    }

    res.set<bool>("showOverAllStar", showOverAllStar);
    return res;
}

Response BarrierDestroyStrategy::clear(Parameter* parameter) {
    Response res;
    BarrierBizLogic barrierBizLogic;
    std::vector<int> barrierIdVector = parameter->get<std::vector<int>>("barrierIdVector");
    bool ret = barrierBizLogic.destroy(barrierIdVector);
    if (false == ret) {
        res.setStatus(ServiceStatus::FAILD);
    }
    return res;
}

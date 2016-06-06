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
#include "BattleStatusStrategy.h"
#include "OverAllBizLogic.h"

BattleStatusStrategy::BattleStatusStrategy() {}

BattleStatusStrategy::~BattleStatusStrategy() {}

Response BattleStatusStrategy::get(Parameter* parameter) {
    OverAllBizLogic overAllBizLogic;
    int overAllRate = overAllBizLogic.getCurrentPercent();

    Response res;
    res.set<int>("overAllRate", overAllRate);
    return res;
}
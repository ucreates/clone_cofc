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
#include "MasterCreateStrategy.h"
#include "UnitBizLogic.h"
#include "BarrierBizLogic.h"

MasterCreateStrategy::MasterCreateStrategy() {}

MasterCreateStrategy::~MasterCreateStrategy() {}

Response MasterCreateStrategy::update(Parameter* parameter) {
    UnitBizLogic unitBizLogic;
    unitBizLogic.create();

    BarrierBizLogic barrierBizLogic;
    barrierBizLogic.create();

    Response res;
    return res;
}
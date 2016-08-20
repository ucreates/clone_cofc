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
#include "LogoClearStrategy.h"
#include "RouteBizLogic.h"
#include "AssetBizLogic.h"
#include "BarrierBizLogic.h"
#include "OverAllBizLogic.h"
#include "ResourceBizLogic.h"
#include "UnitBizLogic.h"
LogoClearStrategy::LogoClearStrategy() {}
LogoClearStrategy::~LogoClearStrategy() {}
Response LogoClearStrategy::update(Parameter* parameter) {
    std::list<BaseBizLogic*> list;
    list.push_back(new AssetBizLogic());
    list.push_back(new BarrierBizLogic());
    list.push_back(new OverAllBizLogic());
    list.push_back(new ResourceBizLogic());
    list.push_back(new RouteBizLogic());
    list.push_back(new UnitBizLogic());
    for (std::list<BaseBizLogic*>::iterator it = list.begin(); it != list.end(); it++) {
        (*it)->clear();
        CC_SAFE_DELETE((*it));
    }
    list.clear();
    Response res;
    return res;
}
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
#include "UnitMoveStrategy.h"
#include "RouteBizLogic.h"

UnitMoveStrategy::UnitMoveStrategy() {}

UnitMoveStrategy::~UnitMoveStrategy() {}

Response UnitMoveStrategy::get(Parameter* parameter) {
    unsigned int startGeographicId = parameter->get<int>("startGeographicId");
    unsigned int goalGeographicId = parameter->get<int>("goalGeographicId");
    RouteBizLogic routeBizLogic;
    std::vector<GeographicNode*> routeCacheVector = routeBizLogic.getRouteCache(startGeographicId, goalGeographicId);
    Response res;
    res.set<std::vector<GeographicNode*>>("routeCacheVector", routeCacheVector);
    return res;
}

Response UnitMoveStrategy::update(Parameter* parameter) {
    unsigned int startGeographicId = parameter->get<int>("startGeographicId");
    unsigned int goalGeographicId = parameter->get<int>("goalGeographicId");
    std::vector<GeographicNode*> routeVector = parameter->get<std::vector<GeographicNode*>>("routeVector");
    RouteBizLogic routeBizLogic;
    bool ret = routeBizLogic.addRouteCache(startGeographicId, goalGeographicId, routeVector);
    Response res;
    if (false == ret) {
        res.setStatus(ServiceStatus::FAILD);
    }
    return res;
}

Response UnitMoveStrategy::clear(Parameter* parameter) {
    unsigned int startGeographicId = parameter->get<int>("startGeographicId");
    unsigned int goalGeographicId = parameter->get<int>("goalGeographicId");
    RouteBizLogic routeBizLogic;
    bool ret = routeBizLogic.removeRouteCache(startGeographicId, goalGeographicId);
    Response res;
    if (false == ret) {
        res.setStatus(ServiceStatus::FAILD);
    }
    return res;
}
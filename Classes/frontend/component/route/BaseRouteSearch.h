//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseRouteSearch_h
#define BaseRouteSearch_h
// stl
#include <vector>
// geographic
#include "GeographicNode.h"
// route
#include "RouteCollection.h"
#include "RouteCacheCollection.h"
class BaseRouteSearch {
   public:
    virtual std::vector<GeographicNode*> execute();
    virtual bool isValidStartNode(GeographicNode* node);
    virtual bool isValidEndNode(GeographicNode* node);
    BaseRouteSearch();
    virtual ~BaseRouteSearch();
    void setStartNode(GeographicNode* start);
    void setGoalNode(GeographicNode* end);
    GeographicNode* getStartNode();
    GeographicNode* getGoalNode();
   protected:
    GeographicNode* startNode;
    GeographicNode* goalNode;
    RouteCacheCollection* routeCache;
    bool isReadyExecute();
};
#endif

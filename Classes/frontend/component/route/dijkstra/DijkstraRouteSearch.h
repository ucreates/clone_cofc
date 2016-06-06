//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef DijkstraRouteSearch_h
#define DijkstraRouteSearch_h

#include <vector>
#include "GeographicNode.h"

// route
#include "BaseRouteSearch.h"
#include "RouteLink.h"
#include "RouteCollection.h"
#include "RouteEvalCollection.h"

class DijkstraRouteSearch : public BaseRouteSearch {
   public:
    static const int ROUTE_SEARCH_ALGORITHM_ID = 3;
    DijkstraRouteSearch();
    DijkstraRouteSearch(GeographicNode* start, GeographicNode* end);
    virtual ~DijkstraRouteSearch();
    void initialize(GeographicNode* start, GeographicNode* end);
    std::vector<GeographicNode*> execute() override;
    bool addEvalNode(GeographicNode* node);
    bool addNodeLink(GeographicNode* start, GeographicNode* goal);
    bool addNodeLink(RouteLink* link);
    RouteEvalCollection* getRouteEvalCollection();
    std::vector<RouteLink*>* getNodeLinkVector();

   protected:
    std::vector<RouteLink*>* linkVector;
    RouteCollection* shortestRoute;
    RouteEvalCollection* routeEvalCollection;
    RouteEvalCollection* routeEvaluatedCollection;
    std::vector<GeographicNode*>* nodeCacheVector;
};
#endif

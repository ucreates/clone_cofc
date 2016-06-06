//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef AstarRouteSearch_h
#define AstarRouteSearch_h

#include <vector>
#include "GeographicNode.h"
#include "BaseRouteSearch.h"
#include "RouteCollection.h"
#include "BaseAstarHeuristic.h"
#include "AstarTwoPointDistanceHeuristic.h"
#include "RouteEvalCollection.h"
#include "AddressRangeValidator.h"

class AstarRouteSearch : public BaseRouteSearch {
   public:
    static const int SEARCH_NODE_UNIT_SIZE = 1;
    static const int ROUTE_SEARCH_ALGORITHM_ID = 2;
    AstarRouteSearch();
    AstarRouteSearch(GeographicNode* start, GeographicNode* end, int heuristicId = AstarTwoPointDistanceHeuristic::ASTAR_HEURISTIC_ID);
    virtual ~AstarRouteSearch();
    std::vector<GeographicNode*> execute() override;
    void changeHeuristic(int heuristicId);
    RouteEvalCollection* getOpenList();
    RouteEvalCollection* getCloseList();

   protected:
    BaseAstarHeuristic* heuristic;
    RouteEvalCollection* openList;
    RouteEvalCollection* closeList;
    AddressRangeValidator* validator;
    virtual bool isValidNode(GeographicNode* node);
    void initialize(GeographicNode* start, GeographicNode* end);
    std::vector<GeographicNode*> getNextNodeVector(GeographicNode* evalNode);
};

#endif
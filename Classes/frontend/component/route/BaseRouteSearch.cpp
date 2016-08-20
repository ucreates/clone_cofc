//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BaseRouteSearch.h"
BaseRouteSearch::BaseRouteSearch() { this->routeCache = new RouteCacheCollection(); }
BaseRouteSearch::~BaseRouteSearch() { CC_SAFE_DELETE(this->routeCache); }
std::vector<GeographicNode*> BaseRouteSearch::execute() {
    std::vector<GeographicNode*> pointVector;
    return pointVector;
}
void BaseRouteSearch::setStartNode(GeographicNode* start) { this->startNode = start; }
void BaseRouteSearch::setGoalNode(GeographicNode* end) { this->goalNode = end; }
GeographicNode* BaseRouteSearch::getStartNode() { return this->startNode; }
GeographicNode* BaseRouteSearch::getGoalNode() { return this->goalNode; }
bool BaseRouteSearch::isReadyExecute() {
    if (NULL == this->startNode || this->goalNode == NULL) {
        return false;
    }
    return true;
}
bool BaseRouteSearch::isValidStartNode(GeographicNode* node) { return true; }
bool BaseRouteSearch::isValidEndNode(GeographicNode* node) { return true; }

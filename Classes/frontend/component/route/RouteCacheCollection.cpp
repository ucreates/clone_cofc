//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "RouteCacheCollection.h"
RouteCacheCollection::RouteCacheCollection() { this->routeCacheVector = new std::vector<RouteCollection>(); }
RouteCacheCollection::~RouteCacheCollection() { CC_SAFE_DELETE(this->routeCacheVector); }
RouteCollection RouteCacheCollection::findLeastCache() {
    RouteCollection result;
    int shortestDistance = INT32_MAX;
    std::vector<RouteCollection>::iterator st;
    for (std::vector<RouteCollection>::iterator it = this->routeCacheVector->begin(); it != this->routeCacheVector->end(); it++) {
        RouteCollection shortestRoute = (RouteCollection)(*it);
        int distance = shortestRoute.getDistance();
        if (shortestDistance > distance) {
            shortestDistance = distance;
            result = shortestRoute;
            st = it;
        }
    }
    if (0 < this->routeCacheVector->size()) {
        this->routeCacheVector->erase(st);
    }
    return result;
}
RouteCollection RouteCacheCollection::findByGeographicNode(GeographicNode* evalNode) {
    RouteCollection result;
    int shortestDistance = INT32_MAX;
    std::vector<RouteCollection>::iterator st;
    for (std::vector<RouteCollection>::iterator it = this->routeCacheVector->begin(); it != this->routeCacheVector->end(); it++) {
        RouteCollection shortestRoute = (RouteCollection)(*it);
        std::vector<GeographicNode*> nodeVector = shortestRoute.getNodeVector();
        int lastIndex = nodeVector.size() - 1;
        GeographicNode* lastNode = nodeVector.at(lastIndex);
        if (lastNode->geographicId != evalNode->geographicId) {
            continue;
        }
        int distance = shortestRoute.getDistance();
        if (shortestDistance > distance) {
            shortestDistance = distance;
            result = shortestRoute;
            st = it;
        }
    }
    return result;
}
void RouteCacheCollection::save(int distance, std::vector<GeographicNode*> nodeVector) { this->routeCacheVector->push_back(RouteCollection(distance, nodeVector)); }
void RouteCacheCollection::erase(GeographicNode* evalNode) {
    for (std::vector<RouteCollection>::iterator it = this->routeCacheVector->begin(); it != this->routeCacheVector->end(); it++) {
        RouteCollection shortestRoute = (RouteCollection)(*it);
        std::vector<GeographicNode*> nodeVector = shortestRoute.getNodeVector();
        int lastIndex = nodeVector.size() - 1;
        GeographicNode* lastNode = nodeVector.at(lastIndex);
        if (lastNode->geographicId == evalNode->geographicId) {
            this->routeCacheVector->erase(it);
            break;
        }
    }
    return;
}
bool RouteCacheCollection::isEmpty() { return this->routeCacheVector->empty(); }
void RouteCacheCollection::clear() {
    this->routeCacheVector->clear();
    return;
}

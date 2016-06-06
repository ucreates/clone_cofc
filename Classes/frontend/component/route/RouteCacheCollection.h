//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef RouteCacheCollection_h
#define RouteCacheCollection_h

// stl
#include <vector>

// cocos2d
#include "cocos2d.h"

// geographic
#include "GeographicNode.h"

// route
#include "RouteCollection.h"

class RouteCacheCollection {
   public:
    RouteCacheCollection();
    ~RouteCacheCollection();
    RouteCollection findLeastCache();
    RouteCollection findByGeographicNode(GeographicNode* evalNode);
    void save(int distance, std::vector<GeographicNode*> nodeVector);
    void erase(GeographicNode* evalNode);
    bool isEmpty();
    void clear();

   private:
    std::vector<RouteCollection>* routeCacheVector;
};

#endif

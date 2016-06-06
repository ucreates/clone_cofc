//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef RouteLink_h
#define RouteLink_h

#include <vector>
#include "cocos2d.h"
#include "GeographicNode.h"

class RouteLink {
   public:
    RouteLink(GeographicNode* start, GeographicNode* goal);
    virtual ~RouteLink();
    void setStartNode(GeographicNode* start);
    void setGoalNode(GeographicNode* goal);
    GeographicNode* getStartNode();
    GeographicNode* getGoalNode();
    int getDistance();
    bool isEvaluatedNode(GeographicNode* node);
    bool isEvaluatedStartNode(GeographicNode* node);
    bool isEvaluatedGoalNode(GeographicNode* node);
    bool isSameLink(GeographicNode* start, GeographicNode* goal);

   private:
    int id;
    GeographicNode* start;
    GeographicNode* goal;
    int distance;
};

#endif

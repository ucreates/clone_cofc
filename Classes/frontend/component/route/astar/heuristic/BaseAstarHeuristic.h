//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseAstarHeuristic_h
#define BaseAstarHeuristic_h
#include "GeographicNode.h"
class BaseAstarHeuristic {
   public:
    static const int ASTAR_HEURISTIC_ID = 1;
    BaseAstarHeuristic();
    virtual ~BaseAstarHeuristic();
    virtual int getEstimateDistance();
    void setStartNode(GeographicNode* node);
    void setGoalNode(GeographicNode* node);
   protected:
    GeographicNode* start;
    GeographicNode* goal;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef AstarManhattanHeuristic_h
#define AstarManhattanHeuristic_h
#include "BaseAstarHeuristic.h"
#include "GeographicNode.h"
class AstarManhattanHeuristic : public BaseAstarHeuristic {
   public:
    static const int ASTAR_HEURISTIC_ID = 3;
    AstarManhattanHeuristic();
    virtual ~AstarManhattanHeuristic();
    int getEstimateDistance() override;
};
#endif

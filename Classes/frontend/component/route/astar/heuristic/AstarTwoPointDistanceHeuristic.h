//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef AstarTwoPointDistanceHeuristic_h
#define AstarTwoPointDistanceHeuristic_h

#include "BaseAstarHeuristic.h"
#include "GeographicNode.h"

class AstarTwoPointDistanceHeuristic : public BaseAstarHeuristic {
   public:
    static const int ASTAR_HEURISTIC_ID = 2;
    AstarTwoPointDistanceHeuristic();
    virtual ~AstarTwoPointDistanceHeuristic();
    int getEstimateDistance() override;
};

#endif

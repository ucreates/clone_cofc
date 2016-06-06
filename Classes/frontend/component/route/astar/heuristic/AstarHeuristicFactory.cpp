//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "AstarHeuristicFactory.h"
#include "AstarManhattanHeuristic.h"
#include "AstarTwoPointDistanceHeuristic.h"

BaseAstarHeuristic* AstarHeuristicFactory::factoryMethod(int heuristicId) {
    BaseAstarHeuristic* heuristic = NULL;
    switch (heuristicId) {
        case BaseAstarHeuristic::ASTAR_HEURISTIC_ID:
            heuristic = new BaseAstarHeuristic();
            break;
        case AstarTwoPointDistanceHeuristic::ASTAR_HEURISTIC_ID:
            heuristic = new AstarTwoPointDistanceHeuristic();
            break;
        case AstarManhattanHeuristic::ASTAR_HEURISTIC_ID:
            heuristic = new AstarManhattanHeuristic();
            break;
        default:
            break;
    }
    return heuristic;
}
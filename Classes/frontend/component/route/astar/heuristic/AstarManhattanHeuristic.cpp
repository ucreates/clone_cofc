//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "AstarManhattanHeuristic.h"
#include "Distance.h"
AstarManhattanHeuristic::AstarManhattanHeuristic() {}
AstarManhattanHeuristic::~AstarManhattanHeuristic() {}
int AstarManhattanHeuristic::getEstimateDistance() {
    int xdist = this->start->address.x - this->goal->address.x;
    int ydist = this->start->address.y - this->goal->address.y;
    int distanceOfNextToGoal = abs(xdist) + abs(ydist);
    return distanceOfNextToGoal;
}
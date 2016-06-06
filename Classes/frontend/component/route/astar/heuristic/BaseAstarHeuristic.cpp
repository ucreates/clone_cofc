//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BaseAstarHeuristic.h"

BaseAstarHeuristic::BaseAstarHeuristic() {
    this->start = NULL;
    this->goal = NULL;
}

BaseAstarHeuristic::~BaseAstarHeuristic() {}

int BaseAstarHeuristic::getEstimateDistance() { return 1; }

void BaseAstarHeuristic::setStartNode(GeographicNode* node) { this->start = node; }

void BaseAstarHeuristic::setGoalNode(GeographicNode* node) { this->goal = node; }

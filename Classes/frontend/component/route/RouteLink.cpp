//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "RouteLink.h"
#include "Distance.h"

RouteLink::RouteLink(GeographicNode* start, GeographicNode* goal) {
    if (NULL == start || NULL == goal) {
        return;
    }

    this->distance = Distance::create(start->address, goal->address);
    this->start = start;
    this->goal = goal;
}

RouteLink::~RouteLink() {}

void RouteLink::setStartNode(GeographicNode* start) { this->start = start; }

void RouteLink::setGoalNode(GeographicNode* goal) { this->goal = goal; }

GeographicNode* RouteLink::getStartNode() { return this->start; }

GeographicNode* RouteLink::getGoalNode() { return this->goal; }

int RouteLink::getDistance() { return this->distance; }

bool RouteLink::isEvaluatedNode(GeographicNode* node) { return (this->start->geographicId == node->geographicId || this->goal->geographicId == node->geographicId); }

bool RouteLink::isEvaluatedStartNode(GeographicNode* node) { return (this->start->geographicId == node->geographicId); }

bool RouteLink::isEvaluatedGoalNode(GeographicNode* node) { return (this->goal->geographicId == node->geographicId); }

bool RouteLink::isSameLink(GeographicNode* start, GeographicNode* goal) { return (this->start->geographicId == start->geographicId && this->goal->geographicId == goal->geographicId); }

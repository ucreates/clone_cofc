//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "RouteCollection.h"

RouteCollection::RouteCollection() { this->distance = INT_MAX; }

RouteCollection::RouteCollection(int distance, std::vector<GeographicNode*> routePointVector) {
    this->distance = distance;
    this->nodeVector = routePointVector;
}

RouteCollection::~RouteCollection() {}

std::vector<GeographicNode*> RouteCollection::getNodeVector() {
    GeographicGateway* gateway = GeographicGateway::getInstance();
    for (std::vector<GeographicNode*>::iterator it = nodeVector.begin(); it != nodeVector.end(); it++) {
        GeographicNode* nextNode = (*it);
        this->validator.setProperty(nextNode->address);
        if (false == this->validator.isValid()) {
            continue;
        }
        nextNode = gateway->findByAddress(&nextNode->address);
        (*it) = nextNode;
    }
    return this->nodeVector;
}

void RouteCollection::setNodeVector(std::vector<GeographicNode*> routePointVector) { this->nodeVector = routePointVector; }

int RouteCollection::getDistance() { return this->distance; }

void RouteCollection::setDistance(int distance) { this->distance = distance; }
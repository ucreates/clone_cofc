//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "DijkstraRouteSearch.h"
#include "Distance.h"

DijkstraRouteSearch::DijkstraRouteSearch() : DijkstraRouteSearch(NULL, NULL) {}

DijkstraRouteSearch::DijkstraRouteSearch(GeographicNode* start, GeographicNode* end) {
    this->startNode = start;
    this->goalNode = end;
    this->linkVector = new std::vector<RouteLink*>();
    this->routeEvalCollection = new RouteEvalCollection();
    this->nodeCacheVector = new std::vector<GeographicNode*>();
    this->shortestRoute = new RouteCollection();
    this->routeEvaluatedCollection = new RouteEvalCollection();
}

DijkstraRouteSearch::~DijkstraRouteSearch() {
    for (std::vector<RouteLink*>::iterator it = linkVector->begin(); it != linkVector->end(); ++it) {
        RouteLink* link = (RouteLink*)(*it);
        delete link;
    }

    CC_SAFE_DELETE(this->linkVector);
    CC_SAFE_DELETE(this->routeEvalCollection);
    CC_SAFE_DELETE(this->routeEvaluatedCollection);
    CC_SAFE_DELETE(this->shortestRoute);
    CC_SAFE_DELETE(this->routeCache);
}

void DijkstraRouteSearch::initialize(GeographicNode* start, GeographicNode* end) {
    this->startNode = start;
    this->goalNode = end;

    this->routeCache->clear();
    std::vector<GeographicNode*> routeNodeVector;
    routeNodeVector.push_back(start);
    this->routeCache->save(0, routeNodeVector);

    this->shortestRoute->setDistance(INT32_MAX);

    if (this->routeEvalCollection->isEmpty()) {
        this->routeEvalCollection = new RouteEvalCollection();
        std::vector<GeographicNode*>::iterator it = this->nodeCacheVector->begin();
        while (it != this->nodeCacheVector->end()) {
            this->routeEvalCollection->save((GeographicNode*)(*it));
            it++;
        }
    }

    this->routeEvaluatedCollection->clear();
}

std::vector<GeographicNode*> DijkstraRouteSearch::execute() {
    std::vector<GeographicNode*> emptyret;
    if (false == this->isReadyExecute()) {
        return emptyret;
    }

    this->initialize(this->startNode, this->goalNode);

    for (;;) {
        if (this->routeEvalCollection->isEmpty()) {
            return this->shortestRoute->getNodeVector();
        }

        RouteCollection shortestRoute = this->routeCache->findLeastCache();

        std::vector<GeographicNode*> routeNodeVector = shortestRoute.getNodeVector();

        int lastIndex = routeNodeVector.size() - 1;

        GeographicNode* evalNode = routeNodeVector.at(lastIndex);

        this->routeEvalCollection->erase(evalNode);

        int distanceOfEvalNode = shortestRoute.getDistance();

        if (evalNode->address == this->goalNode->address) {
            if (this->shortestRoute->getDistance() > distanceOfEvalNode) {
                this->shortestRoute->setDistance(distanceOfEvalNode);
                this->shortestRoute->setNodeVector(routeNodeVector);
            }
        }

        if (this->routeEvaluatedCollection->isEvaluatedNode(evalNode)) {
            continue;
        }

        this->routeEvaluatedCollection->save(evalNode);

        for (std::vector<RouteLink*>::iterator it = this->linkVector->begin(); it != this->linkVector->end(); it++) {
            RouteLink* link = (RouteLink*)(*it);

            int distanceOfEvalNodeToNextNode = 0;

            GeographicNode* nextNode = NULL;
            if (link->getStartNode()->geographicId == evalNode->geographicId) {
                distanceOfEvalNodeToNextNode = link->getDistance();
                nextNode = link->getGoalNode();
            }

            if (link->getGoalNode()->geographicId == evalNode->geographicId) {
                distanceOfEvalNodeToNextNode = link->getDistance();
                nextNode = link->getStartNode();
            }

            if (nextNode == NULL) {
                continue;
            }

            int newShortestDistance = distanceOfEvalNode + distanceOfEvalNodeToNextNode;
            RouteCollection shortestRouteHistory = this->routeCache->findByGeographicNode(nextNode);
            if (shortestRouteHistory.getDistance() > newShortestDistance) {
                std::vector<GeographicNode*> newRouteNodeVector;
                copy(routeNodeVector.begin(), routeNodeVector.end(), back_inserter(newRouteNodeVector));
                newRouteNodeVector.push_back(nextNode);
                this->routeCache->save(newShortestDistance, newRouteNodeVector);
            }
        }
    }
}

RouteEvalCollection* DijkstraRouteSearch::getRouteEvalCollection() { return this->routeEvalCollection; }

std::vector<RouteLink*>* DijkstraRouteSearch::getNodeLinkVector() { return this->linkVector; }

bool DijkstraRouteSearch::addEvalNode(GeographicNode* node) {
    if (this->routeEvalCollection->isEvaluatedNode(node)) {
        return false;
    }

    this->routeEvalCollection->save(node);
    this->nodeCacheVector->push_back(node);
    return true;
}

bool DijkstraRouteSearch::addNodeLink(GeographicNode* start, GeographicNode* goal) {
    int addLinkCount = 0;
    for (std::vector<RouteLink*>::iterator it = linkVector->begin(); it != linkVector->end(); it++) {
        RouteLink* link = (RouteLink*)(*it);
        if (link->isSameLink(start, goal)) {
            addLinkCount++;
        }

        if (link->isSameLink(goal, start)) {
            addLinkCount++;
        }
    }

    if (2 > addLinkCount) {
        this->linkVector->push_back(new RouteLink(start, goal));
        this->linkVector->push_back(new RouteLink(goal, start));
        this->addEvalNode(start);
        this->addEvalNode(goal);
        return true;
    }
    return false;
}
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "AstarRouteSearch.h"
#include "AstarManhattanHeuristic.h"
#include "AstarHeuristicFactory.h"
#include "Distance.h"
#include "BarrierBehaviourType.h"

using namespace cocos2d;

AstarRouteSearch::AstarRouteSearch() : AstarRouteSearch(NULL, NULL) {}

AstarRouteSearch::~AstarRouteSearch() {
    CC_SAFE_DELETE(this->openList);
    CC_SAFE_DELETE(this->closeList);
    CC_SAFE_DELETE(this->heuristic);
    CC_SAFE_DELETE(this->validator);
}

AstarRouteSearch::AstarRouteSearch(GeographicNode* start, GeographicNode* end, int heuristicId) {
    this->openList = new RouteEvalCollection();
    this->closeList = new RouteEvalCollection();
    this->heuristic = AstarHeuristicFactory::factoryMethod(heuristicId);
    this->validator = new AddressRangeValidator();
    this->initialize(start, end);
}

void AstarRouteSearch::initialize(GeographicNode* start, GeographicNode* end) {

    this->startNode = start;

    this->goalNode = end;

    this->closeList->clear();

    this->openList->clear();
    this->openList->save(start);

    this->routeCache->clear();
    std::vector<GeographicNode*> routeNodeVector;
    routeNodeVector.push_back(start);

    this->routeCache->save(0, routeNodeVector);
}

std::vector<GeographicNode*> AstarRouteSearch::execute() {
    if (false == this->isReadyExecute()) {
        std::vector<GeographicNode*> emptyVector;
        return emptyVector;
    }

    this->initialize(this->startNode, this->goalNode);

    for (;;) {
        if (this->openList->isEmpty()) {
            std::vector<GeographicNode*> emptyVector;
            return emptyVector;
        }

        RouteCollection shortestRoute = this->routeCache->findLeastCache();

        std::vector<GeographicNode*> routeNodeVector = shortestRoute.getNodeVector();

        int lastIndex = routeNodeVector.size() - 1;
        GeographicNode* evalNode = routeNodeVector.at(lastIndex);

        this->openList->erase(evalNode);

        if (this->goalNode->address == evalNode->address) {
            return routeNodeVector;
        } else {
            this->closeList->save(evalNode);

            int fn = shortestRoute.getDistance();
            this->heuristic->setStartNode(evalNode);
            this->heuristic->setGoalNode(this->goalNode);
            int hn = this->heuristic->getEstimateDistance();
            int gn = fn - hn;

            std::vector<GeographicNode*> nextNodeVector = this->getNextNodeVector(evalNode);

            for (int i = 0; i < nextNodeVector.size(); i++) {
                GeographicNode* nextNode = nextNodeVector.at(i);

                if (false == this->isValidNode(nextNode)) {
                    continue;
                }

                std::vector<GeographicNode*> estimateRouteNodeVector;
                copy(routeNodeVector.begin(), routeNodeVector.end(), back_inserter(estimateRouteNodeVector));

                int costNtoM = Distance::create(evalNode->address, nextNode->address);

                this->heuristic->setStartNode(nextNode);
                this->heuristic->setGoalNode(this->goalNode);
                int hm = this->heuristic->getEstimateDistance();

                int fdm = gn + costNtoM + hm;

                RouteCollection cachedShotestRoute = this->routeCache->findByGeographicNode(nextNode);
                int fm = cachedShotestRoute.getDistance();

                if (!this->openList->isEvaluatedNode(nextNode) && !this->closeList->isEvaluatedNode(nextNode)) {
                    this->openList->save(nextNode);
                    estimateRouteNodeVector.push_back(nextNode);
                    this->routeCache->save(fdm, estimateRouteNodeVector);
                }

                if (this->openList->isEvaluatedNode(nextNode)) {
                    if (fdm < fm) {
                        this->routeCache->erase(nextNode);
                        estimateRouteNodeVector.push_back(nextNode);
                        this->routeCache->save(fdm, estimateRouteNodeVector);
                    }
                }

                if (this->closeList->isEvaluatedNode(nextNode)) {
                    if (fdm < fm) {
                        this->closeList->erase(nextNode);
                        this->openList->save(nextNode);

                        this->routeCache->erase(nextNode);
                        estimateRouteNodeVector.push_back(nextNode);
                        this->routeCache->save(fdm, estimateRouteNodeVector);
                    }
                }
            }
        }
    }
}

std::vector<GeographicNode*> AstarRouteSearch::getNextNodeVector(GeographicNode* evalNode) {
    int x = evalNode->address.x;
    int y = evalNode->address.y;

    std::vector<Address> searchAddressVector;
    searchAddressVector.push_back(Address(x + AstarRouteSearch::SEARCH_NODE_UNIT_SIZE, y));
    searchAddressVector.push_back(Address(x - AstarRouteSearch::SEARCH_NODE_UNIT_SIZE, y));
    searchAddressVector.push_back(Address(x, y + AstarRouteSearch::SEARCH_NODE_UNIT_SIZE));
    searchAddressVector.push_back(Address(x, y - AstarRouteSearch::SEARCH_NODE_UNIT_SIZE));
    searchAddressVector.push_back(Address(x + AstarRouteSearch::SEARCH_NODE_UNIT_SIZE, y + AstarRouteSearch::SEARCH_NODE_UNIT_SIZE));
    searchAddressVector.push_back(Address(x + AstarRouteSearch::SEARCH_NODE_UNIT_SIZE, y - AstarRouteSearch::SEARCH_NODE_UNIT_SIZE));
    searchAddressVector.push_back(Address(x - AstarRouteSearch::SEARCH_NODE_UNIT_SIZE, y + AstarRouteSearch::SEARCH_NODE_UNIT_SIZE));
    searchAddressVector.push_back(Address(x - AstarRouteSearch::SEARCH_NODE_UNIT_SIZE, y - AstarRouteSearch::SEARCH_NODE_UNIT_SIZE));

    GeographicGateway* gateway = GeographicGateway::getInstance();
    std::vector<GeographicNode*> result;
    for (std::vector<Address>::iterator it = searchAddressVector.begin(); it != searchAddressVector.end(); it++) {
        Address searchAddress = (Address)(*it);
        this->validator->setProperty(searchAddress);
        if (this->validator->isValid()) {
            GeographicNode* node = gateway->findByAddress(&searchAddress);
            result.push_back(node);
        }
    }
    return result;
}

bool AstarRouteSearch::isValidNode(GeographicNode* node) {
    this->validator->setProperty(node->address);
    if (this->validator->isValid() && (node->type == BarrierBehaviourType::None || this->goalNode->geographicId == node->geographicId || BarrierBehaviourType::WoodFenceH == node->type || BarrierBehaviourType::WoodFenceV == node->type)) {
        return true;
    }

    return false;
}

void AstarRouteSearch::changeHeuristic(int heuristicId) {
    CC_SAFE_DELETE(this->heuristic);
    this->heuristic = AstarHeuristicFactory::factoryMethod(heuristicId);
}

RouteEvalCollection* AstarRouteSearch::getOpenList() { return this->openList; }

RouteEvalCollection* AstarRouteSearch::getCloseList() { return this->closeList; }

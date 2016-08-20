//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "UnitMoveState.h"
#include "ArcherBehaviour.h"
#include "BarbarianBehaviour.h"
#include "GiantBehaviour.h"
#include "GoblinBehaviour.h"
#include "WallBreakerBehaviour.h"
#include "BeaconEffectBehaviour.h"
#include "BehaviourMapper.h"
#include "BehaviourCollection.h"
#include "Notifier.h"
// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
#include "GeographicDepth.h"
// utility
#include "Distance.h"
#include "Degree.h"
// vfx
#include "Move.h"
#include "ServiceGateway.h"
#include "Parameter.h"
#include "Response.h"
#include "AstarRouteSearch.h"
#include "Direction.h"
using namespace cocos2d;
std::mutex unitMoveMtx;
template <typename T>
UnitMoveState<T>::UnitMoveState() {
    this->routeSearch = new AstarRouteSearch(NULL, NULL, AstarTwoPointDistanceHeuristic::ASTAR_HEURISTIC_ID);
    this->speed = 1.0f;
}
template <typename T>
UnitMoveState<T>::~UnitMoveState() {
    CC_SAFE_DELETE(this->routeSearch);
}
template <typename T>
void UnitMoveState<T>::search() {
    this->routeVector.clear();
    std::thread thread = std::thread([this]() {
        unitMoveMtx.lock();
        GeographicNode* start = NULL;
        GeographicNode* goal = NULL;
        GeographicGateway* gateway = GeographicGateway::getInstance();
        Vec2 pos = this->asset->getTransform().getPosition().vector2d;
        if (false != this->firstSearch) {
            start = gateway->findByPosition(pos);
            this->firstSearch = false;
        } else {
            start = this->routeSearch->getGoalNode();
        }
        goal = this->findGoalNode(start);
        if (NULL == goal) {
            this->unit->stateMachine->stop();
            this->changeDirection();
            unitMoveMtx.unlock();
            return;
        }
        Parameter parameter;
        parameter.set<int>("startGeographicId", start->geographicId);
        parameter.set<int>("goalGeographicId", goal->geographicId);
        Response res = ServiceGateway::getInstance()->request("service://unit/move")->get(&parameter);
        std::vector<GeographicNode*> routeCacheVector = res.get<std::vector<GeographicNode*>>("routeCacheVector");
        res.clear();
        this->routeVector.clear();
        if (0 == routeCacheVector.size()) {
            this->routeSearch->setStartNode(start);
            this->routeSearch->setGoalNode(goal);
            this->routeVector = this->routeSearch->execute();
            Parameter parameter;
            parameter.set<int>("startGeographicId", start->geographicId);
            parameter.set<int>("goalGeographicId", goal->geographicId);
            parameter.set<std::vector<GeographicNode*>>("routeVector", this->routeVector);
            Response res = ServiceGateway::getInstance()->request("service://unit/move")->update(&parameter);
            res.clear();
        } else {
            this->routeVector = routeCacheVector;
            int lastIndex = routeCacheVector.size() - 1;
            this->routeSearch->setStartNode(routeCacheVector.at(0));
            this->routeSearch->setGoalNode(routeCacheVector.at(lastIndex));
        }
        this->unit->setGeographicNode(start);
        this->changeDirection();
        parameter.set<GeographicNode*>("goalGeographicNode", goal);
        this->unit->getBeacon()->getStateMachine()->change("show", &parameter);
        this->unit->stateMachine->play();
        unitMoveMtx.unlock();
    });
    thread.detach();
}
template <typename T>
GeographicNode* UnitMoveState<T>::findGoalNode(GeographicNode* startNode) {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    return collection->findBarrierByPosition(startNode, true);
}
template <typename T>
bool UnitMoveState<T>::move(GeographicNode* goalNode) {
    bool ret = false;
    this->asset->transform(goalNode->depth + GeographicDepth::UNIT_DEPTH_RELATIVE_TO_NODE);
    Position pos = this->asset->getTransform().getPosition();
    int distance = Distance::create(pos.vector2d, goalNode->position);
    if (UnitMoveState::MOST_NEAR_DISTANCE < distance) {
        Vec2 npos = Move::execute(pos.vector2d, goalNode->position, this->speed);
        this->asset->transform(npos);
    } else {
        this->asset->transform(goalNode->position);
        this->unit->setGeographicNode(goalNode);
        this->changeDirection();
        ret = true;
    }
    return ret;
}
template <typename T>
void UnitMoveState<T>::changeDirection() {
    if (0 == this->routeVector.size()) {
        return;
    }
    GeographicNode* currentNode = this->unit->getGeographicNode();
    GeographicNode* destinationNode = NULL;
    if (1 < this->routeVector.size()) {
        destinationNode = this->routeVector.at(1);
    } else {
        destinationNode = this->routeVector.at(0);
    }
    float degree = Degree::create(currentNode->position, destinationNode->position);
    Direction::DIRECT direction = Direction::getDirection(degree);
    if (direction == Direction::DIRECT::HORIZON_RIGHT) {
        asset->play("side_walk");
        asset->transform(false);
    } else if (direction == Direction::DIRECT::HORIZON_LEFT) {
        asset->play("side_walk");
        asset->transform(true);
    } else if (direction == Direction::DIRECT::UPPER_RIGHT) {
        asset->play("upper_walk");
        asset->transform(false);
    } else if (direction == Direction::DIRECT::UPPER_LEFT) {
        asset->play("upper_walk");
        asset->transform(true);
    } else if (direction == Direction::DIRECT::UNDER_RIGHT) {
        asset->play("under_walk");
        asset->transform(false);
    } else if (direction == Direction::DIRECT::UNDER_LEFT) {
        asset->play("under_walk");
        asset->transform(true);
    }
}
template <typename T>
void UnitMoveState<T>::setUnit(T* unit) {
    this->unit = unit;
}
template class UnitMoveState<ArcherBehaviour>;
template class UnitMoveState<BarbarianBehaviour>;
template class UnitMoveState<GiantBehaviour>;
template class UnitMoveState<GoblinBehaviour>;
template class UnitMoveState<WallBreakerBehaviour>;
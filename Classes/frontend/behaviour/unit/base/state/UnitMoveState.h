//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UnitMoveState_h
#define UnitMoveState_h
// state
#include "FiniteState.h"
// route
#include "BaseRouteSearch.h"
// asset
#include "AnimatorAsset.h"
#include "GeographicNode.h"
template <class T>
class UnitMoveState {
   public:
    UnitMoveState();
    virtual ~UnitMoveState();
   protected:
    T* unit;
    const int MOST_NEAR_DISTANCE = 1;
    BaseRouteSearch* routeSearch;
    std::vector<GeographicNode*> routeVector;
    bool firstSearch;
    bool pause;
    bool init;
    AnimatorAsset* asset;
    float speed;
    void search();
    virtual GeographicNode* findGoalNode(GeographicNode* startNode);
    bool move(GeographicNode* goalNode);
    void changeDirection();
    void setUnit(T* unit);
};
#endif

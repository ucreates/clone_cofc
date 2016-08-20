//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef CannonSearchState_h
#define CannonSearchState_h
// stl
#include <vector>
// state
#include "FiniteState.h"
// behaviour
#include "CannonBehaviour.h"
#include "BaseUnitBehaviour.h"
// route
#include "BaseRouteSearch.h"
// frame
#include "TimeLine.h"
// asset
#include "BaseRenderAsset.h"
#include "AnimatorAsset.h"
class CannonBehaviour;
class CannonSearchState : public FiniteState<CannonBehaviour> {
   public:
    CannonSearchState();
    virtual ~CannonSearchState();
    void create() override;
    void update(float delta) override;
   private:
    static int const MAX_FRAME_NUMBER = 35;
    static const int MOST_SHORTEST_DISTANCE = 1000;
    TimeLine* counterTimeLine;
    AnimatorAsset* asset;
    int maxFrameNumber;
    int searchDirection;
    float lastTargetDegree;
    BaseUnitBehaviour* target;
    bool finishSearch;
    bool finishCalc;
    void search();
    bool calcDegree();
};
#endif

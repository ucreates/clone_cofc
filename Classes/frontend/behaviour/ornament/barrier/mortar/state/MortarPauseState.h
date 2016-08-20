//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef MortarPauseState_h
#define MortarPauseState_h
// stl
#include <vector>
// state
#include "FiniteState.h"
// behaviour
#include "BaseUnitBehaviour.h"
#include "MortarBehaviour.h"
// frame
#include "TimeLine.h"
// asset
#include "AnimatorAsset.h"
class MortarBehaviour;
class MortarPauseState : public FiniteState<MortarBehaviour> {
   public:
    MortarPauseState();
    virtual ~MortarPauseState();
    void create() override;
    void update(float delta) override;
   private:
    static const int MOST_SHORTEST_DISTANCE = 1000;
    constexpr static const float SHOT_TIME = 7.0f;
    AnimatorAsset* asset;
    bool enableSearch;
    GeographicNode* targetNode;
    BaseUnitBehaviour* search();
};
#endif

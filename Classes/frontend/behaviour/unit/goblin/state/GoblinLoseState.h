//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GoblinLoseState_h
#define GoblinLoseState_h
// state
#include "FiniteState.h"
#include "UnitLoseState.h"
// behaviour
#include "GoblinBehaviour.h"
// asset
#include "AnimatorAsset.h"
class GoblinBehaviour;
class GoblinLoseState : public FiniteState<GoblinBehaviour>, UnitLoseState<GoblinBehaviour> {
   public:
    GoblinLoseState();
    virtual ~GoblinLoseState();
    void create() override;
};
#endif

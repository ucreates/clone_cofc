//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GrassBehaviour_h
#define GrassBehaviour_h
#include "BaseOrnamentBehaviour.h"
#include "FiniteStateMachine.h"
#include "GrassBehaviourShowState.h"
#include "IFiniteStateMachine.h"
class GrassBehaviourShowState;
class GrassBehaviour : public BaseOrnamentBehaviour, public IFiniteStateMachine<GrassBehaviour> {
    friend GrassBehaviourShowState;
   public:
    GrassBehaviour(GeographicNode* geographicNode);
    virtual ~GrassBehaviour();
    void onCreate() override;
};
#endif
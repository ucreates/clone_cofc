//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GrassBehaviourShowState_h
#define GrassBehaviourShowState_h
#include "FiniteState.h"
#include "GrassBehaviour.h"
class GrassBehaviour;
class GrassBehaviourShowState : public FiniteState<GrassBehaviour> {
   public:
    GrassBehaviourShowState();
    virtual ~GrassBehaviourShowState();
    void create(Parameter* parameter) override;
};
#endif

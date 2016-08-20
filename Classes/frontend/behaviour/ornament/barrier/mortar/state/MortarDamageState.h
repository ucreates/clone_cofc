//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef MortarDamageState_h
#define MortarDamageState_h
// stl
#include <vector>
// state
#include "FiniteState.h"
// behaviour
#include "MortarBehaviour.h"
// route
#include "BaseRouteSearch.h"
// frame
#include "TimeLine.h"
#include "Parameter.h"
class GoldStrageBehaviour;
class MortarDamageState : public FiniteState<MortarBehaviour> {
   public:
    MortarDamageState();
    virtual ~MortarDamageState();
    void create(Parameter* parameter) override;
   private:
    BaseStrategy* damageStrategy;
};
#endif

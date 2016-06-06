//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef CannonDamageState_h
#define CannonDamageState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "CannonBehaviour.h"

// frame
#include "TimeLine.h"

#include "Parameter.h"
#include "BaseStrategy.h"

class CannonBehaviour;

class CannonDamageState : public FiniteState<CannonBehaviour> {
   public:
    CannonDamageState();
    ~CannonDamageState();
    void create(Parameter* parameter) override;

   private:
    BaseStrategy* damageStrategy;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef MortarAttackState_h
#define MortarAttackState_h

// stl
#include <vector>

// state
#include "FiniteState.h"

// behaviour
#include "MortarBehaviour.h"
#include "MortarBulletBehaviour.h"

// route
#include "BaseRouteSearch.h"

// frame
#include "TimeLine.h"

class MortarBehaviour;

class MortarAttackState : public FiniteState<MortarBehaviour> {
   public:
    MortarAttackState(int ownerId);
    virtual ~MortarAttackState();
    void create(Parameter* parameter) override;

   private:
    GeographicNode* targetNode;
    MortarBulletBehaviour* bullet;
};

#endif

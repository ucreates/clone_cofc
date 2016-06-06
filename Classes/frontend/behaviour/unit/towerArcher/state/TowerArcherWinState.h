//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TowerArcherWinState_h
#define TowerArcherWinState_h

// state
#include "FiniteState.h"
#include "UnitWinState.h"

// behaviour
#include "TowerArcherBehaviour.h"

class TowerArcherBehaviour;
class TowerArcherWinState : public FiniteState<TowerArcherBehaviour>, UnitWinState<TowerArcherBehaviour> {
   public:
    TowerArcherWinState();
    virtual ~TowerArcherWinState();
    void create() override;
};

#endif

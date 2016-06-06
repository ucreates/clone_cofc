//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TowerArcherLoseState_h
#define TowerArcherLoseState_h

// state
#include "FiniteState.h"
#include "UnitLoseState.h"

// behaviour
#include "TowerArcherBehaviour.h"

// asset
#include "AnimatorAsset.h"

class TowerArcherBehaviour;
class TowerArcherLoseState : public FiniteState<TowerArcherBehaviour>, UnitLoseState<TowerArcherBehaviour> {
   public:
    TowerArcherLoseState();
    virtual ~TowerArcherLoseState();
    void create() override;
};

#endif

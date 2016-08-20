//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TowerArcherSearchState_h
#define TowerArcherSearchState_h
// state
#include "FiniteState.h"
// behaviour
#include "TowerArcherBehaviour.h"
// asset
#include "AnimatorAsset.h"
#include "Direction.h"
class TowerArcherBehaviour;
class TowerArcherSearchState : public FiniteState<TowerArcherBehaviour> {
   public:
    TowerArcherSearchState();
    virtual ~TowerArcherSearchState();
    void create() override;
    void create(Parameter* parameter) override;
    void update(float delta) override;
   private:
    AnimatorAsset* asset;
    void changeDirection(Direction::DIRECT direction);
};
#endif

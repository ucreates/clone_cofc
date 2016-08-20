//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ArrowDestoryState_h
#define ArrowDestoryState_h
// state
#include "FiniteState.h"
// behaviour
#include "ArrowBehaviour.h"
// asset
#include "BaseRenderAsset.h"
class ArrowBehaviour;
class ArrowDestroyState : public FiniteState<ArrowBehaviour> {
   public:
    ArrowDestroyState();
    virtual ~ArrowDestroyState();
    void create() override;
};
#endif

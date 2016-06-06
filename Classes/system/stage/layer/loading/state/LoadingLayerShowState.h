//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LoadingLayerShowState_h
#define LoadingLayerShowState_h

// layer
#include "LoadingLayer.h"

// state
#include "FiniteState.h"

class LoadingLayerShowState : public FiniteState<LoadingLayer> {
   public:
    LoadingLayerShowState();
    virtual ~LoadingLayerShowState();
    void create() override;
    void update(float delta) override;
};

#endif

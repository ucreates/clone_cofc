//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LoadingLayerTransitionState_h
#define LoadingLayerTransitionState_h
// layer
#include "LoadingLayer.h"
// state
#include "FiniteState.h"
#include "BaseTransitionState.h"
class LoadingLayerTransitionState : public FiniteState<LoadingLayer>, public BaseTransitionState<LoadingLayer> {
   public:
    LoadingLayerTransitionState();
    virtual ~LoadingLayerTransitionState();
    void create() override;
};
#endif

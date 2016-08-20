//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LogoLayerTransitionState_h
#define LogoLayerTransitionState_h
// state
#include "FiniteState.h"
// layer
#include "LogoLayer.h"
#include "BaseTransitionState.h"
class LogoLayerTransitionState : public FiniteState<LogoLayer>, public BaseTransitionState<LogoLayer> {
   public:
    LogoLayerTransitionState();
    virtual ~LogoLayerTransitionState();
    void create() override;
};
#endif

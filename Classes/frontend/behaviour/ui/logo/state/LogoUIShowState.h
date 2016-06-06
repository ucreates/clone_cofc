//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef FadeInState_h
#define FadeInState_h
#include "FiniteState.h"
#include "LogoUIBehaviour.h"

class LogoUIBehaviour;

class LogoUIShowState : public FiniteState<LogoUIBehaviour> {
   public:
    LogoUIShowState();
    virtual ~LogoUIShowState();
    void create() override;
};

#endif

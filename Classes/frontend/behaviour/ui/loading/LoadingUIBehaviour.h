//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LogoUIBehaviour_h
#define LogoUIBehaviour_h
#include "BaseBehaviour.h"
#include "IFiniteStateMachine.h"
#include "LoadingUILoadingState.h"
#include "INotify.h"

class LoadingUILoadingState;

class LoadingUIBehaviour : public BaseBehaviour, public IFiniteStateMachine<LoadingUIBehaviour>, public INotify {
    friend LoadingUILoadingState;

   public:
    LoadingUIBehaviour();
    virtual ~LoadingUIBehaviour();
    void onCreate(cocos2d::Layer* layer, int depth = 0) override;
    void onUpdate(float time = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};

#endif

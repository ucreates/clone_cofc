//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LoadingLayer_h
#define LoadingLayer_h

// layer
#include "BaseLayer.h"
#include "LoadingLayerBuilder.h"

// notifier
#include "INotify.h"

// state
#include "FiniteStateMachine.h"
#include "BaseTransitionState.h"
#include "IFiniteStateMachine.h"

class LoadingLayer : public BaseLayer, public IFiniteStateMachine<LoadingLayer>, public INotify {
    friend LoadingLayerBuilder;
    friend BaseTransitionState<LoadingLayer>;

   public:
    static const int LAYER_ID = 2;
    bool init() override;
    void update(float delta) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
    void onExit() override;
    CREATE_FUNC(LoadingLayer);
};

#endif
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LogoLayer_h
#define LogoLayer_h

// layer
#include "BaseLayer.h"

// notify
#include "INotify.h"

// state
#include "IFiniteStateMachine.h"
#include "BaseTransitionState.h"

class LogoLayerBuilder;

class LogoLayer : public BaseLayer, public IFiniteStateMachine<LogoLayer>, public INotify {
    friend LogoLayerBuilder;
    friend BaseTransitionState<LogoLayer>;

   public:
    static const int LAYER_ID = 1;
    bool init() override;
    void update(float delta) override;
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
    void onExit() override;
    CREATE_FUNC(LogoLayer);
};

#endif
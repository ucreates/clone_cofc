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
#include "cocos2d.h"
#include "BaseBehaviour.h"
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "LogoUIShowState.h"
#include "INotify.h"
class LogoUIShowState;
class LogoUIBehaviour : public BaseBehaviour, public IFiniteStateMachine<LogoUIBehaviour>, public INotify {
    friend LogoUIShowState;
   public:
    LogoUIBehaviour();
    virtual ~LogoUIBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
    void onCreate(cocos2d::Layer* layer, int depth = 0) override;
    void onUpdate(float time = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif

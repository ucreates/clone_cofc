//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BeaconEffectBehaviour_h
#define BeaconEffectBehaviour_h

// cocos2d
#include "cocos2d.h"

// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "BeaconEffectShowState.h"

// behaviour
#include "BaseBehaviour.h"
#include "INotify.h"

class BeaconEffectShowState;

class BeaconEffectBehaviour : public BaseBehaviour, public IFiniteStateMachine<BeaconEffectBehaviour>, public INotify {
    friend BeaconEffectShowState;

   public:
    BeaconEffectBehaviour();
    virtual ~BeaconEffectBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// behaviour
#include "LoadingUIBehaviour.h"

// layer
#include "LoadingLayer.h"

// state
#include "LoadingLayerShowState.h"
#include "LoadingLayerTransitionState.h"

// notifier
#include "Notifier.h"
#include "NotifyMessage.h"

using namespace cocos2d;

bool LoadingLayer::init() {
    if (false == Layer::init()) {
        return false;
    }

    Layer* uiLayer = Layer::create();

    LoadingLayerBuilder builder;
    builder.setRootLayer(this)->setUILayer(uiLayer)->setProperty("loading")->setSEAsset("sound/se/loading_screen_jingle.mp3")->setUI(new LoadingUIBehaviour())->build();
    return true;
}

void LoadingLayer::update(float delta) { this->stateMachine->update(delta); }

void LoadingLayer::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Loading_Scene_Show_State) {
        this->stateMachine->change("show");
    } else if (notifyMessage == NotifyMessage::Loading_Scene_Complete_State) {
        this->stateMachine->change("transition");
    }
    this->stateMachine->play();
}

void LoadingLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    if (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE) {
        CC_SAFE_DELETE(this->stateMachine);
        BaseLayer::onKeyReleased(keyCode, event);
    }
    return;
}

void LoadingLayer::onExit() {
    CC_SAFE_DELETE(this->stateMachine);
    BaseLayer::onExit();
}
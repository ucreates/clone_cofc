//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// builder
#include "LogoLayerBuilder.h"

// behaviour
#include "LogoUIBehaviour.h"
#include "BehaviourCollection.h"

// layer
#include "LogoLayer.h"

// geographic
#include "GeographicGateway.h"

// notify
#include "Notifier.h"

using namespace cocos2d;

bool LogoLayer::init() {
    if (false == Layer::init()) {
        return false;
    }

    Layer* uiLayer = Layer::create();

    LogoLayerBuilder builder;
    builder.setRootLayer(this)->setUILayer(uiLayer)->setProperty("logo")->setSEAsset("sound/se/supercell_jingle.mp3")->setUI(new LogoUIBehaviour())->build();
    return true;
}

void LogoLayer::update(float delta) { this->stateMachine->update(delta); }

void LogoLayer::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Logo_Scene_Show_State) {
        this->stateMachine->change("show");
    } else if (notifyMessage == NotifyMessage::Logo_Scene_Complete_State) {
        this->stateMachine->change("transition");
    }
    this->stateMachine->play();
}

void LogoLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    if (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE) {
        CC_SAFE_DELETE(this->stateMachine);
        BaseLayer::onKeyReleased(keyCode, event);
    }
    return;
}

void LogoLayer::onExit() {
    CC_SAFE_DELETE(this->stateMachine);
    BaseLayer::onExit();
}
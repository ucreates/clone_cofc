//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "LoadingUIBehaviour.h"
#include "BehaviourIdGenerator.h"
#include "UIProperty.h"
#include "Notifier.h"
#include "UIAsset.h"
#include "SoundAssetCollection.h"

using namespace cocos2d;

LoadingUIBehaviour::LoadingUIBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("ui", new UIAsset("csb/scene/loading/layer/loading"));
    this->asset->add("jingle", SoundAssetCollection::getInstance()->getSEAsset("sound/se/loading_screen_jingle.mp3"));
    this->property = new UIProperty("loading", id);
    this->stateMachine = new FiniteStateMachine<LoadingUIBehaviour>(this);
    this->stateMachine->add("show", new LoadingUILoadingState());
    this->stateMachine->stop();

    Notifier::getInstance()->add(this, this->property);
}

LoadingUIBehaviour::~LoadingUIBehaviour() {}

void LoadingUIBehaviour::onCreate(Layer* layer, int depth) {
    BaseRenderAsset* asset = (BaseRenderAsset*)this->asset->find("ui");
    asset->addLayer(layer, depth);
    return;
}

void LoadingUIBehaviour::onUpdate(float time) {
    this->stateMachine->update(time);
    return;
}

void LoadingUIBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Loading_Scene_Show_State) {
        this->stateMachine->change("show");
    }
    this->stateMachine->play();
    return;
}
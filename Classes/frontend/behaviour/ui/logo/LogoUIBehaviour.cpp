//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "LogoUIBehaviour.h"
#include "GeographicDepth.h"
#include "UIProperty.h"
#include "Notifier.h"
#include "UIAsset.h"
#include "BehaviourIdGenerator.h"
#include "SoundAssetCollection.h"
using namespace cocos2d;
LogoUIBehaviour::LogoUIBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("ui", new UIAsset("csb/scene/logo/layer/logo"));
    this->asset->add("jingle", SoundAssetCollection::getInstance()->getSEAsset("sound/se/supercell_jingle.mp3"));
    this->property = new UIProperty("logo", id);
    this->stateMachine = new FiniteStateMachine<LogoUIBehaviour>(this);
    this->stateMachine->add("fadein", new LogoUIShowState());
    this->stateMachine->stop();
    Notifier::getInstance()->add(this, this->property);
}
LogoUIBehaviour::~LogoUIBehaviour() {}
void LogoUIBehaviour::onCreate(Layer* layer) {
    this->onCreate(layer, GeographicDepth::UI_DEPTH);
    return;
}
void LogoUIBehaviour::onCreate(Layer* layer, int depth) {
    BaseRenderAsset* asset = (BaseRenderAsset*)this->asset->find("ui");
    asset->addLayer(layer, depth);
    this->stateMachine->change("fadein");
    this->stateMachine->play();
    return;
}
void LogoUIBehaviour::onUpdate(float time) {
    this->stateMachine->update(time);
    return;
}
void LogoUIBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Logo_Scene_Show_State) {
        this->stateMachine->change("fadein");
    }
    this->stateMachine->play();
    return;
}
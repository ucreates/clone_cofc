//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "CloudEffectBehaviour.h"
#include "cocostudio/CocoStudio.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "EffectProperty.h"
#include "GeographicDepth.h"
// asset
#include "AnimatorAsset.h"
// notify
#include "Notifier.h"
#include "NotifyMessage.h"
#include "Screen.h"
#include "Response.h"
#include "ServiceGateway.h"
using namespace cocos2d;
using namespace cocostudio::timeline;
CloudEffectBehaviour::CloudEffectBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/effect/cloud", id));
    this->complete = false;
    this->frame = new TimeLine();
    this->property = new EffectProperty("cloud", id);
}
CloudEffectBehaviour::~CloudEffectBehaviour() { CC_SAFE_DELETE(this->frame); }
void CloudEffectBehaviour::onCreate(Layer* layer) {
    // asset
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    Position pos = Screen::getCenterPosition();
    anime->transform(pos.vector2d);
    anime->addLayer(layer, GeographicDepth::EFFECT_DEPTH_RELATIVE_TO_NODE);
    anime->pause();
}
void CloudEffectBehaviour::onUpdate(float delta) {
    float time = this->frame->getFrameTime();
    if (1.0f < time && false == this->complete) {
        AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
        std::function<void(Frame*)> callback = [this](Frame* frame) {
            EventFrame* eFrame = dynamic_cast<EventFrame*>(frame);
            std::string eName = eFrame->getEvent();
            if (eName == "onStartZoom") {
                Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_Observation_State);
            } else if (eName == "onAnimationStop") {
                this->property->setStatus(BehaviourStatus::COMPLETE);
            }
        };
        anime->play("show", callback, false);
        this->complete = true;
    }
    this->frame->update(delta);
}
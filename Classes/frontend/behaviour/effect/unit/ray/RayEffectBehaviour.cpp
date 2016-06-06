//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "RayEffectBehaviour.h"

#include "BehaviourIdGenerator.h"

// peroperty
#include "EffectProperty.h"

// asset
#include "AnimatorAsset.h"

// notify
#include "Notifier.h"

using namespace cocos2d;

RayEffectBehaviour::RayEffectBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/effect/ray", id));
    this->property = new EffectProperty("ray", id);
}

RayEffectBehaviour::~RayEffectBehaviour() {}

void RayEffectBehaviour::onCreate(Layer* layer, Position position) {
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position);
    anime->transform(Size(0.75f, 0.75f));
    anime->addLayer(layer, position.zorder);
    anime->play("show", false);
}
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "MotarSmokeEffectBehaviour.h"

#include "BehaviourIdGenerator.h"

// peroperty
#include "EffectProperty.h"
#include "GeographicDepth.h"

// asset
#include "ParticleAsset.h"
#include "SoundEffectAsset.h"
#include "SoundAssetCollection.h"

// notify
#include "Notifier.h"

using namespace cocos2d;

MotarSmokeEffectBehaviour::MotarSmokeEffectBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new ParticleAsset("particle/motar/smoke.plist"));
    this->asset->add("se", SoundAssetCollection::getInstance()->getSEAsset("sound/se/mortar_fire_02_with_fall.mp3"));
    this->property = new EffectProperty("motarSmoke", id);
}

MotarSmokeEffectBehaviour::~MotarSmokeEffectBehaviour() {}

void MotarSmokeEffectBehaviour::onCreate(Layer* layer, Position position) {
    // asset
    ParticleAsset* particle = (ParticleAsset*)this->getAsset("anime");
    particle->transform(position);
    particle->transform(0.4f);
    particle->addLayer(layer, GeographicDepth::EFFECT_DEPTH_RELATIVE_TO_NODE);

    SoundEffectAsset* se = (SoundEffectAsset*)this->getAsset("se");
    se->play();

    this->property->setStatus(BehaviourStatus::COMPLETE);
}
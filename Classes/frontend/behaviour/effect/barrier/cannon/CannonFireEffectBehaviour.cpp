//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "CannonFireEffectBehaviour.h"
#include "BehaviourIdGenerator.h"
#include "GeographicDepth.h"
// peroperty
#include "EffectProperty.h"
// asset
#include "ParticleAsset.h"
#include "SoundEffectAsset.h"
#include "SoundAssetCollection.h"
// notify
#include "Notifier.h"
using namespace cocos2d;
CannonFireEffectBehaviour::CannonFireEffectBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("render1", new ParticleAsset("particle/cannon/fire.plist"));
    this->asset->add("render2", new ParticleAsset("particle/cannon/smoke.plist"));
    this->asset->add("se", SoundAssetCollection::getInstance()->getSEAsset("sound/se/cannon_08.mp3"));
    this->property = new EffectProperty("cannonFire", id);
}
CannonFireEffectBehaviour::~CannonFireEffectBehaviour() {}
void CannonFireEffectBehaviour::onCreate(Layer* layer, Position position) {
    // asset
    std::string particleList[2] = {"render1", "render2"};
    for (int i = 0; i < 2; i++) {
        std::string particleName = particleList[i];
        ParticleAsset* particle = (ParticleAsset*)this->getAsset(particleName);
        particle->transform(position);
        particle->addLayer(layer, position.zorder + GeographicDepth::EFFECT_DEPTH_RELATIVE_TO_NODE - i);
    }
    SoundEffectAsset* se = (SoundEffectAsset*)this->getAsset("se");
    se->play();
    this->property->setStatus(BehaviourStatus::COMPLETE);
}
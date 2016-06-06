//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "DestroyEffectBehaviour.h"

#include "BehaviourIdGenerator.h"

// peroperty
#include "EffectProperty.h"

// asset
#include "ParticleAsset.h"
#include "SoundEffectAsset.h"
#include "SoundAssetCollection.h"

// notify
#include "Notifier.h"

using namespace cocos2d;

DestroyEffectBehaviour::DestroyEffectBehaviour(BaseProperty* property) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("render1", new ParticleAsset("particle/destruction/wood1.plist"));
    this->asset->add("render2", new ParticleAsset("particle/destruction/wood2.plist"));
    this->asset->add("render3", new ParticleAsset("particle/destruction/wood3.plist"));
    this->asset->add("render4", new ParticleAsset("particle/destruction/wood4.plist"));
    this->asset->add("se", SoundAssetCollection::getInstance()->getSEAsset("sound/se/building_destroyed_01.mp3"));
    this->property = new EffectProperty("destroy", id);
    OrnamentProperty* ornamentProperty = (OrnamentProperty*)property;
    Address* scale = ornamentProperty->getAddressScale();
    this->effectScale = DestroyEffectBehaviour::BASIC_SCALE * (float)(scale->x + scale->y + scale->z) / 3.0f;
}

DestroyEffectBehaviour::~DestroyEffectBehaviour() {}

void DestroyEffectBehaviour::onCreate(Layer* layer, Position position) {
    // asset
    std::string particleList[4] = {"render1", "render2", "render3", "render4"};
    for (int i = 0; i < 4; i++) {
        std::string particleName = particleList[i];
        ParticleAsset* particle = (ParticleAsset*)this->getAsset(particleName);
        particle->transform(this->effectScale);
        particle->transform(position);
        particle->addLayer(layer, position.zorder);
    }

    SoundEffectAsset* se = (SoundEffectAsset*)this->getAsset("se");
    se->play();

    this->property->setStatus(BehaviourStatus::COMPLETE);
}
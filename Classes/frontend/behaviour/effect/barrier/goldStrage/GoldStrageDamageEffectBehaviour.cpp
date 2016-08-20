//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "GoldStrageDamageEffectBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "EffectProperty.h"
// asset
#include "ParticleAsset.h"
// notify
#include "Notifier.h"
using namespace cocos2d;
GoldStrageDamageEffectBehaviour::GoldStrageDamageEffectBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new ParticleAsset("particle/gold/gold.plist"));
    this->property = new EffectProperty("goldStrageDamage", id);
}
GoldStrageDamageEffectBehaviour::~GoldStrageDamageEffectBehaviour() {}
void GoldStrageDamageEffectBehaviour::onCreate(Layer* layer, Position position) {
    // asset
    ParticleAsset* particle = (ParticleAsset*)this->getAsset("anime");
    particle->transform(position);
    particle->addLayer(layer, position.zorder);
    this->property->setStatus(BehaviourStatus::COMPLETE);
}
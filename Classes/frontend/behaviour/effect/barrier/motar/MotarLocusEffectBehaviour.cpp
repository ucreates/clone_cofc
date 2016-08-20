//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "MotarLocusEffectBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "EffectProperty.h"
#include "GeographicDepth.h"
// asset
#include "ParticleAsset.h"
// notify
#include "Notifier.h"
using namespace cocos2d;
MotarLocusEffectBehaviour::MotarLocusEffectBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new ParticleAsset("particle/motar/locus.plist"));
    this->property = new EffectProperty("motarLocus", id);
}
MotarLocusEffectBehaviour::~MotarLocusEffectBehaviour() {}
void MotarLocusEffectBehaviour::onCreate(Layer* layer, Position position) {
    // asset
    ParticleAsset* particle = (ParticleAsset*)this->getAsset("anime");
    particle->transform(position);
    particle->addLayer(layer, position.zorder + GeographicDepth::EFFECT_DEPTH_RELATIVE_TO_NODE);
    this->property->setStatus(BehaviourStatus::COMPLETE);
}
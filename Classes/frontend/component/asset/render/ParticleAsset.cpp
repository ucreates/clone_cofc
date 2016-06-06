//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "cocos2d.h"
#include "ParticleAsset.h"

using namespace cocos2d;

ParticleAsset::ParticleAsset(std::string textureFileName) {
    this->particle = ParticleSystemQuad::create(textureFileName);
    this->particle->retain();
    this->particle->setBlendAdditive(false);
}

ParticleAsset::~ParticleAsset() {}

void ParticleAsset::transform(float scale) { this->particle->setScale(scale); }

void ParticleAsset::transform(GLubyte alpha) { this->particle->setOpacity(alpha); }

void ParticleAsset::transform(Position position) {
    this->particle->setPosition(position.x, position.y);
    this->particle->setLocalZOrder(position.zorder);
}

void ParticleAsset::addLayer(Layer* layer, int depth) {
    this->particle->setAutoRemoveOnFinish(true);
    layer->addChild(this->particle, depth);
}

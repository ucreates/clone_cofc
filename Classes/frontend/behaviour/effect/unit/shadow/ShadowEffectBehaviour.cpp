//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "ShadowEffectBehaviour.h"
#include "AnimatorAsset.h"
#include "TextureAsset.h"

using namespace cocos2d;

ShadowEffectBehaviour::ShadowEffectBehaviour(BaseBehaviour* owner) {
    this->unit = owner;
    this->asset->add("texture", new TextureAsset("img/unit/shadow/shadow.png"));
}

ShadowEffectBehaviour::~ShadowEffectBehaviour() {}

void ShadowEffectBehaviour::onCreate(cocos2d::Layer* layer, Position position, cocos2d::Size scale) {
    // asset
    Position pos = position;
    pos.add(Vec2(0.0f, -20.0f));
    pos.add(-1);
    BaseRenderAsset* texture = (BaseRenderAsset*)this->getAsset("texture");
    texture->transform(pos);
    texture->transform(scale);
    texture->addLayer(layer, pos.zorder);
    texture->show();
}

void ShadowEffectBehaviour::onUpdate(float delta) {
    AnimatorAsset* ownerAnime = (AnimatorAsset*)this->unit->getAsset("anime");
    Position pos = ownerAnime->getTransform().getPosition();
    pos.add(Vec2(0.0f, -20.0f));
    pos.add(-1);
    BaseRenderAsset* texture = (BaseRenderAsset*)this->getAsset("texture");
    texture->transform(pos);
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BattleBackGroundBehaviour.h"
#include "BehaviourIdGenerator.h"
#include "BackGroundProperty.h"
#include "Screen.h"
#include "TextureAsset.h"
using namespace cocos2d;

BattleBackGroundBehaviour::BattleBackGroundBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("texture", new TextureAsset("img/battle/bg.png"));
    this->property = new BackGroundProperty("texture", id);
}

BattleBackGroundBehaviour::~BattleBackGroundBehaviour() {}

void BattleBackGroundBehaviour::onCreate(Layer* layer) {
    Position pos = Screen::getCenterPosition();
    BaseRenderAsset* texture = (BaseRenderAsset*)this->getAsset("texture");
    texture->transform(pos.x, pos.y, pos.zorder);
    texture->addLayer(layer, pos.zorder);
    return;
}

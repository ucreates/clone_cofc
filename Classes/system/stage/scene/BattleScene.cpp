//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BattleScene.h"
#include "LayerFactory.h"
#include "BattleLayer.h"

using namespace cocos2d;

BattleScene::BattleScene() {}

BattleScene::~BattleScene() {}

cocos2d::Scene* BattleScene::create() {
    Scene* scene = Scene::create();
    Layer* layer = LayerFactory::factoryMethod(BattleLayer::LAYER_ID);
    scene->addChild(layer);
    return scene;
}

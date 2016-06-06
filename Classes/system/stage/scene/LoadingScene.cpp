//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "LoadingScene.h"
#include "LoadingLayer.h"
#include "LayerFactory.h"

using namespace cocos2d;

LoadingScene::LoadingScene() {}

LoadingScene::~LoadingScene() {}

Scene* LoadingScene::create() {
    Scene* scene = Scene::create();
    Layer* layer = LayerFactory::factoryMethod(LoadingLayer::LAYER_ID);
    scene->addChild(layer);
    scene->retain();
    return scene;
}

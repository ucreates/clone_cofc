//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "LogoScene.h"
#include "LogoLayer.h"
#include "LayerFactory.h"
using namespace cocos2d;
LogoScene::LogoScene() {}
LogoScene::~LogoScene() {}
Scene* LogoScene::create() {
    Scene* scene = Scene::create();
    Layer* layer = LayerFactory::factoryMethod(LogoLayer::LAYER_ID);
    scene->addChild(layer);
    return scene;
}

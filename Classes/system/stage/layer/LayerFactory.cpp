//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// layer
#include "LayerFactory.h"
#include "BattleLayer.h"
#include "LogoLayer.h"
#include "LoadingLayer.h"

using namespace cocos2d;

Layer* LayerFactory::factoryMethod(int layerId) {
    Layer* layer = NULL;
    switch (layerId) {
        case BattleLayer::LAYER_ID:
            layer = BattleLayer::create();
            break;
        case LoadingLayer::LAYER_ID:
            layer = LoadingLayer::create();
            break;
        case LogoLayer::LAYER_ID:
            layer = LogoLayer::create();
            break;
        default:
            break;
    }
    return layer;
}
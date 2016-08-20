//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// behaviour
#include "BaseBehaviour.h"
using namespace cocos2d;
BaseBehaviour::BaseBehaviour() {
    this->asset = new AssetCollection();
    this->geographicNode = NULL;
    this->property = NULL;
}
BaseBehaviour::~BaseBehaviour() {
    this->geographicNode = NULL;
    CC_SAFE_DELETE(this->property);
    CC_SAFE_DELETE(this->asset);
}
void BaseBehaviour::onCreate() { return; }
void BaseBehaviour::onCreate(Layer* layer) { return; }
void BaseBehaviour::onCreate(Layer* layer, int depth) { return; }
void BaseBehaviour::onCreate(Layer* layer, Position position) { return; }
void BaseBehaviour::onCreate(cocos2d::Layer* layer, Position position, cocos2d::Size scale) { return; }
void BaseBehaviour::onUpdate(float time) { return; }
void BaseBehaviour::onCollision() {}
BaseAsset* BaseBehaviour::getAsset(std::string assetName) {
    if (NULL == this->asset) {
        return NULL;
    }
    return this->asset->find(assetName);
}
BaseProperty* BaseBehaviour::getProperty() { return this->property; }
Layer* BaseBehaviour::getLayer() { return this->layer; }
GeographicNode* BaseBehaviour::getGeographicNode() { return this->geographicNode; }
void BaseBehaviour::setGeographicNode(GeographicNode* node) { this->geographicNode = node; }
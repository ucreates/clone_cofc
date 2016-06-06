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
#include "AssetCollection.h"
using namespace cocos2d;

AssetCollection::AssetCollection() { this->assetMap = new std::map<std::string, BaseAsset*>(); }

AssetCollection::~AssetCollection() {
    for (std::map<std::string, BaseAsset*>::iterator it = this->assetMap->begin(); it != this->assetMap->end(); ++it) {
        if ("sound" == it->second->getType()) {
            continue;
        }
        CC_SAFE_DELETE(it->second);
    }
    this->assetMap->clear();
    CC_SAFE_DELETE(this->assetMap);
}

BaseAsset* AssetCollection::find(std::string assetName) {
    if (NULL == this->assetMap) {
        return NULL;
    }

    if (this->assetMap->find(assetName) != this->assetMap->end()) {
        std::map<std::string, BaseAsset*>::iterator it = this->assetMap->find(assetName);
        return (BaseAsset*)(*it).second;
    }
    return NULL;
}

void AssetCollection::add(std::string assetName, BaseAsset* asset) { (*this->assetMap)[assetName] = asset; }

void AssetCollection::erase(std::string assetName) {
    if (this->assetMap->find(assetName) != this->assetMap->end()) {
        std::map<std::string, BaseAsset*>::iterator it = this->assetMap->find(assetName);
        this->assetMap->erase(it);
    }
}

std::map<std::string, BaseAsset*>* AssetCollection::getAssetMap() { return this->assetMap; }
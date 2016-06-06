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
#include "SoundAssetCollection.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

SoundAssetCollection* SoundAssetCollection::instance = NULL;

SoundAssetCollection::SoundAssetCollection() {}

SoundAssetCollection::~SoundAssetCollection() {
    this->stop();
    this->clear();
}

SoundAssetCollection* SoundAssetCollection::getInstance() {
    if (NULL == SoundAssetCollection::instance) {
        SoundAssetCollection::instance = new SoundAssetCollection();
    }
    return SoundAssetCollection::instance;
}

BaseSoundAsset* SoundAssetCollection::getBGMAsset(std::string bgmName) {
    if (this->soundBGMAssetList.find(bgmName) == this->soundBGMAssetList.end()) {
        return NULL;
    }

    return this->soundBGMAssetList[bgmName];
}

BaseSoundAsset* SoundAssetCollection::getSEAsset(std::string seName) {
    if (this->soundEffectAssetList.find(seName) == this->soundEffectAssetList.end()) {
        return NULL;
    }

    return this->soundEffectAssetList[seName];
}

bool SoundAssetCollection::setBGMAsset(std::string bgmName, BaseSoundAsset* asset) {
    if (this->soundBGMAssetList.find(bgmName) != this->soundBGMAssetList.end()) {
        return false;
    }

    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bgmName.c_str());
    this->soundBGMAssetList.insert(std::map<std::string, BaseSoundAsset*>::value_type(bgmName, asset));
    return true;
}

bool SoundAssetCollection::setSEAsset(std::string seName, BaseSoundAsset* asset) {
    if (this->soundEffectAssetList.find(seName) != this->soundEffectAssetList.end()) {
        return false;
    }

    SimpleAudioEngine::getInstance()->preloadEffect(seName.c_str());
    this->soundEffectAssetList.insert(std::map<std::string, BaseSoundAsset*>::value_type(seName, asset));
    return true;
}

void SoundAssetCollection::stop() {
    for (std::map<std::string, BaseSoundAsset*>::iterator it = this->soundEffectAssetList.begin(); it != this->soundEffectAssetList.end(); ++it) {
        it->second->stop();
    }

    for (std::map<std::string, BaseSoundAsset*>::iterator it = this->soundBGMAssetList.begin(); it != this->soundBGMAssetList.end(); ++it) {
        it->second->stop();
    }
}

void SoundAssetCollection::clear() {
    for (std::map<std::string, BaseSoundAsset*>::iterator it = this->soundEffectAssetList.begin(); it != this->soundEffectAssetList.end(); ++it) {
        SimpleAudioEngine::getInstance()->unloadEffect(it->first.c_str());
        CC_SAFE_DELETE(it->second);
    }

    for (std::map<std::string, BaseSoundAsset*>::iterator it = this->soundBGMAssetList.begin(); it != this->soundBGMAssetList.end(); ++it) {
        CC_SAFE_DELETE(it->second);
    }
    this->soundEffectAssetList.clear();
    this->soundBGMAssetList.clear();
}

void SoundAssetCollection::destroy() { CC_SAFE_DELETE(SoundAssetCollection::instance); }
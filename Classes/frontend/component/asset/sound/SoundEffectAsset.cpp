//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "SoundEffectAsset.h"
// cocos2d
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

SoundEffectAsset::SoundEffectAsset(std::string assetFileName) { this->assetFileName = assetFileName; }

SoundEffectAsset::~SoundEffectAsset() {}

void SoundEffectAsset::play() {
    SimpleAudioEngine::getInstance()->setEffectsVolume(0.5f);
    this->soundId = SimpleAudioEngine::getInstance()->playEffect(this->assetFileName.c_str());
    return;
}

void SoundEffectAsset::pause() { return; }

void SoundEffectAsset::stop() {
    SimpleAudioEngine::getInstance()->stopEffect(this->soundId);
    return;
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// cocos2d
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "BGMAsset.h"

using namespace CocosDenshion;

BGMAsset::BGMAsset(std::string assetFileName) {
    this->assetFileName = assetFileName;
    this->isPause = false;
}

BGMAsset::~BGMAsset() {}

void BGMAsset::play(bool loop) {
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0f);
    if (false == this->isPause) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(this->assetFileName.c_str(), loop);
    } else {
        SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        this->isPause = false;
    }
    return;
}

void BGMAsset::pause() {
    if (false != SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
        SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    }
    this->isPause = true;
    return;
}

void BGMAsset::stop() {
    SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    return;
}

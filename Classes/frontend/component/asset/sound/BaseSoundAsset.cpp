//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BaseSoundAsset.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
BaseSoundAsset::BaseSoundAsset() { this->type = "sound"; }
BaseSoundAsset::~BaseSoundAsset() {}
void BaseSoundAsset::play(bool loop) { return; }
void BaseSoundAsset::play() { return; }
void BaseSoundAsset::pause() { return; }
void BaseSoundAsset::stop() { return; }
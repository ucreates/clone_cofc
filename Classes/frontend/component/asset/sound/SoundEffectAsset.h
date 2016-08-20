//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef SoundEffectAsset_h
#define SoundEffectAsset_h
// sound
#include "BaseSoundAsset.h"
class SoundEffectAsset : public BaseSoundAsset {
   public:
    SoundEffectAsset(std::string assetFileName);
    virtual ~SoundEffectAsset();
    void play() override;
    void pause() override;
    void stop() override;
   private:
    unsigned int soundId;
};
#endif

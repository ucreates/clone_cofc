//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef SoundAssetCollection_h
#define SoundAssetCollection_h

#include "BaseSoundAsset.h"

class SoundAssetCollection {
   public:
    ~SoundAssetCollection();
    static SoundAssetCollection* getInstance();
    BaseSoundAsset* getBGMAsset(std::string bgmName);
    BaseSoundAsset* getSEAsset(std::string seName);
    bool setBGMAsset(std::string bgmName, BaseSoundAsset* asset);
    bool setSEAsset(std::string seName, BaseSoundAsset* asset);
    void stop();
    void clear();
    static void destroy();

   private:
    SoundAssetCollection();
    static SoundAssetCollection* instance;
    std::map<std::string, BaseSoundAsset*> soundEffectAssetList;
    std::map<std::string, BaseSoundAsset*> soundBGMAssetList;
};

#endif

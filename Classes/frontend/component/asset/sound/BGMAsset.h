//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BGMAsset_h
#define BGMAsset_h
// sound
#include "BaseSoundAsset.h"
class BGMAsset : public BaseSoundAsset {
   public:
    BGMAsset(std::string assetFileName);
    virtual ~BGMAsset();
    void play(bool loop) override;
    void pause() override;
    void stop() override;
   private:
    bool isPause;
};
#endif

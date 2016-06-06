//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseSoundAsset_h
#define BaseSoundAsset_h

// stl
#include <string>

// asset
#include "BaseAsset.h"

class BaseSoundAsset : public BaseAsset {
   public:
    BaseSoundAsset();
    virtual ~BaseSoundAsset();

    virtual void play(bool loop);
    virtual void play();
    virtual void pause();
    virtual void stop();

   protected:
    std::string assetFileName;
};

#endif

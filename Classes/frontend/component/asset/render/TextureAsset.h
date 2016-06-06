//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef TextureAsset_h
#define TextureAsset_h

#include <string>

#include "BaseRenderAsset.h"

class TextureAsset : public BaseRenderAsset {
   public:
    TextureAsset(std::string textureFileName);
    virtual ~TextureAsset();
};

#endif

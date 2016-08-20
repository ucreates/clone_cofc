//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "TextureAsset.h"
using namespace cocos2d;
TextureAsset::TextureAsset(std::string textureFileName) {
    this->node = Sprite::create(textureFileName.c_str());
    this->node->retain();
}
TextureAsset::~TextureAsset() {}
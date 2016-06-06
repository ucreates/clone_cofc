//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef UIAsset_h
#define UIAsset_h

#include <functional>
#include <string>

// cocos2d
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

// asset
#include "BaseRenderAsset.h"

class UIAsset : public BaseRenderAsset {
   public:
    UIAsset(std::string animationName);
    virtual ~UIAsset();

    void play(std::function<void()> endFrameCallback = NULL);
    void play(int startFrame, int endFrame, std::function<void()> endFrameCallback = NULL, bool loop = false);
    void play(int endFrame, std::function<void()> endFrameCallback = NULL, bool loop = false);
    void play(std::string animationName, std::function<void()> endFrameCallback = NULL, bool loop = false);

    template <typename T>
    T findByName(std::string name);

    Transform getTransform() override;
};
#endif

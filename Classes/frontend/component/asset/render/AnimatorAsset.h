//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef AnimatorAsset_h
#define AnimatorAsset_h

#include <string>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "BaseRenderAsset.h"

class AnimatorAsset : public BaseRenderAsset {
   public:
    AnimatorAsset(std::string animationName, int behaviourId);
    virtual ~AnimatorAsset();
    void play(std::string animationName, bool loop = true);
    void play(std::string animationName, std::function<void()> endFrameCallback, bool loop = true);
    void play(std::string animationName, std::function<void(cocostudio::timeline::Frame *)>, bool loop = true);
    void play(int startFrameNumber, int endFrameNumber, bool loop = false);
    void pause(int frameNumber = 0);
    void stop();
    Transform getTransform() override;
};

#endif

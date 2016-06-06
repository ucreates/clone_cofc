//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ParticleAsset_h
#define ParticleAsset_h

// cocos2d
#include "cocos2d.h"

// asset
#include "BaseRenderAsset.h"

class ParticleAsset : public BaseRenderAsset {
   public:
    ParticleAsset(std::string animationName);
    virtual ~ParticleAsset();
    void transform(float scale) override;
    void transform(GLubyte alpha) override;
    void transform(Position position) override;
    void addLayer(cocos2d::Layer* layer, int depth) override;

   private:
    cocos2d::ParticleSystemQuad* particle;
};

#endif

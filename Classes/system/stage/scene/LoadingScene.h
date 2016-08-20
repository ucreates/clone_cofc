//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LoadingScene_h
#define LoadingScene_h
#include "cocos2d.h"
#include "BaseScene.h"
class LoadingScene : public BaseScene {
   public:
    static const int SCENE_ID = 2;
    LoadingScene();
    virtual ~LoadingScene();
    cocos2d::Scene* create() override;
};
#endif
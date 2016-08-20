//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleScene_h
#define BattleScene_h
#include "BaseScene.h"
class BattleScene : public BaseScene {
   public:
    static const int SCENE_ID = 3;
    BattleScene();
    virtual ~BattleScene();
    cocos2d::Scene* create() override;
};
#endif
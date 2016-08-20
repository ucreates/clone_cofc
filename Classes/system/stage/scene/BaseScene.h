//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseScene_h
#define BaseScene_h
#include "cocos2d.h"
class BaseScene : public cocos2d::Scene {
   public:
    BaseScene();
    ~BaseScene();
    virtual cocos2d::Scene* create();
};
#endif
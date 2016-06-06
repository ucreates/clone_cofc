//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef SceneFactory_h
#define SceneFactory_h
#include "cocos2d.h"

class SceneFactory {
   public:
    static cocos2d::Scene* factoryMethod(int sceneId);
};

#endif
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "SceneFactory.h"
#include "BaseScene.h"
#include "LoadingScene.h"
#include "LogoScene.h"
#include "BattleScene.h"
using namespace cocos2d;
Scene* SceneFactory::factoryMethod(int sceneId) {
    BaseScene* scene = NULL;
    switch (sceneId) {
        case LoadingScene::SCENE_ID:
            scene = new LoadingScene();
            break;
        case BattleScene::SCENE_ID:
            scene = new BattleScene();
            break;
        case LogoScene::SCENE_ID:
            scene = new LogoScene();
            break;
        default:
            break;
    }
    if (NULL == scene) {
        return NULL;
    }
    Scene* cocosScene = scene->create();
    delete scene;
    return cocosScene;
}
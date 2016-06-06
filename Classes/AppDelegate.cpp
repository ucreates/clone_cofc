//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "cocos2d.h"
#include "AppDelegate.h"
#include "LogoScene.h"
#include "SceneFactory.h"

using namespace cocos2d;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

void AppDelegate::initGLContextAttrs() {
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {

    Director* director = Director::getInstance();
    GLView* glview = director->getOpenGLView();
    if (NULL == glview) {
        glview = GLViewImpl::createWithRect("clone_cofc", Rect(0, 0, 960, 640));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);
    director->setAnimationInterval(1.0 / 60);
    Scene* scene = SceneFactory::factoryMethod(LogoScene::SCENE_ID);
    director->runWithScene(scene);
    return true;
}

void AppDelegate::applicationDidEnterBackground() { Director::getInstance()->stopAnimation(); }

void AppDelegate::applicationWillEnterForeground() { Director::getInstance()->startAnimation(); }

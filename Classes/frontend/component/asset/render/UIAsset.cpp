//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "UIAsset.h"
#include "Screen.h"
using namespace cocos2d;
using namespace cocostudio::timeline;
using namespace cocos2d::ui;
UIAsset::UIAsset(std::string animationName) {
    this->relativePath = animationName + "/anime.csb";
    this->node = CSLoader::createNode(this->relativePath.c_str());
    this->node->retain();
    Size scale = Screen::getNodeScaleByScreenSize(this->node);
    this->node->setScale(scale.width, scale.height);
    this->node->setVisible(false);
}
UIAsset::~UIAsset() {}
void UIAsset::play(std::function<void()> endFrameCallback) { this->play(0, 1, endFrameCallback, false); }
void UIAsset::play(int endFrame, std::function<void()> endFrameCallback, bool loop) { this->play(0, endFrame, endFrameCallback, loop); }
void UIAsset::play(int startFrame, int endFrame, std::function<void()> endFrameCallback, bool loop) {
    ActionTimeline* action = CSLoader::createTimeline(this->relativePath.c_str());
    this->node->runAction(action);
    action->gotoFrameAndPlay(startFrame, endFrame, loop);
    if (NULL != endFrameCallback) {
        action->setLastFrameCallFunc(endFrameCallback);
    }
    this->node->setVisible(true);
}
void UIAsset::play(std::string animationName, std::function<void()> endFrameCallback, bool loop) {
    ActionTimeline* action = CSLoader::createTimeline(this->relativePath.c_str());
    this->node->runAction(action);
    action->play(animationName, loop);
    if (NULL != endFrameCallback) {
        action->setLastFrameCallFunc(endFrameCallback);
    }
    this->node->setVisible(true);
}
template <typename T>
T UIAsset::findByName(std::string name) {
    return static_cast<T>(this->node->getChildByName(name));
}
Transform UIAsset::getTransform() {
    Vec2 pos = this->node->getPosition();
    int zorder = this->node->getLocalZOrder();
    float sx = this->node->getScaleX();
    float sy = this->node->getScaleY();
    Size scale = Size(sx, sy);
    Size cscale = this->node->getChildren().at(0)->getContentSize();
    float rotate = this->node->getRotation();
    GLubyte alpha = this->node->getOpacity();
    Transform entity = Transform(pos, zorder, scale, cscale, rotate, alpha);
    return entity;
}
template ui::Button* UIAsset::findByName<ui::Button*>(std::string uiComponentName);
template ui::ListView* UIAsset::findByName<ui::ListView*>(std::string uiComponentName);
template ui::TextField* UIAsset::findByName<ui::TextField*>(std::string uiComponentName);
template ui::CheckBox* UIAsset::findByName<ui::CheckBox*>(std::string uiComponentName);
template ui::LoadingBar* UIAsset::findByName<ui::LoadingBar*>(std::string uiComponentName);
template ui::Text* UIAsset::findByName<ui::Text*>(std::string uiComponentName);
template ui::ImageView* UIAsset::findByName<ui::ImageView*>(std::string uiComponentName);

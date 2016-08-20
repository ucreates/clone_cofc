//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "AnimatorAsset.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace cocostudio::timeline;
AnimatorAsset::AnimatorAsset(std::string animationName, int behaviourId) {
    this->id = behaviourId;
    std::string assetPath = animationName + "/anime.csb";
    this->node = CSLoader::createNode(assetPath.c_str());
    this->node->retain();
    ActionTimeline* action = CSLoader::createTimeline(assetPath.c_str());
    this->node->runAction(action);
    action->setTag(behaviourId);
}
AnimatorAsset::~AnimatorAsset() {}
void AnimatorAsset::play(std::string animationName, bool loop) {
    ActionTimeline* action = (ActionTimeline*)this->node->getActionByTag(this->id);
    action->play(animationName, loop);
}
void AnimatorAsset::play(std::string animationName, std::function<void()> endFrameCallback, bool loop) {
    ActionTimeline* action = (ActionTimeline*)this->node->getActionByTag(this->id);
    action->play(animationName, loop);
    action->setLastFrameCallFunc(endFrameCallback);
}
void AnimatorAsset::play(std::string animationName, std::function<void(Frame*)> frameCallback, bool loop) {
    ActionTimeline* action = (ActionTimeline*)this->node->getActionByTag(this->id);
    action->play(animationName, loop);
    action->setFrameEventCallFunc(frameCallback);
}
void AnimatorAsset::play(int startFrameNumber, int endFrameNumber, bool loop) {
    ActionTimeline* action = (ActionTimeline*)this->node->getActionByTag(this->id);
    action->gotoFrameAndPlay(startFrameNumber, endFrameNumber, loop);
}
void AnimatorAsset::pause(int frameNumber) {
    ActionTimeline* action = (ActionTimeline*)this->node->getActionByTag(this->id);
    action->gotoFrameAndPause(frameNumber);
}
void AnimatorAsset::stop() {
    ActionTimeline* action = (ActionTimeline*)this->node->getActionByTag(this->id);
    action->stop();
}
Transform AnimatorAsset::getTransform() {
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

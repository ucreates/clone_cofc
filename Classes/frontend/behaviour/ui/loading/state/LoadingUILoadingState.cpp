//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "LoadingUILoadingState.h"
#include "Flash.h"
#include "ServiceGateway.h"
#include "AssetBizLogic.h"
#include "SoundEffectAsset.h"
#include "UIAsset.h"
#include "Notifier.h"
using namespace cocos2d;
using namespace cocos2d::ui;
LoadingUILoadingState::LoadingUILoadingState() { this->statementTimeLine = new TimeLine(); }
LoadingUILoadingState::~LoadingUILoadingState() { CC_SAFE_FREE(this->statementTimeLine); }
void LoadingUILoadingState::create() {
    UIAsset* asset = (UIAsset*)this->owner->getAsset("ui");
    this->loadingBar = asset->findByName<LoadingBar*>("downloadGuage");
    this->loadingBar->setPercent(0);
    this->loadingLabel = asset->findByName<Text*>("nowLoadingStatement");
    this->tutorialLabel = asset->findByName<Text*>("tutorialStatement");
    this->tutorialLabel->setOpacity(0.0f);
    Parameter parameter;
    parameter.set<bool>("emitDownload", false);
    Response res = ServiceGateway::getInstance()->request("service://loading/download")->request(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    res.clear();
    SoundEffectAsset* se = (SoundEffectAsset*)this->owner->getAsset("jingle");
    se->play();
    this->reset();
    asset->play();
    return;
}
void LoadingUILoadingState::update(float delta) {
    float percent = this->loadingBar->getPercent();
    if (100.0f <= percent) {
        Notifier::getInstance()->notify(NotifyMessage::Loading_Scene_Complete_State);
        return;
    } else {
        Response res = ServiceGateway::getInstance()->request("service://loading/download")->get();
        float percentage = res.get<float>("downloadPercentage");
        this->loadingBar->setPercent(percentage);
        float currentTime = this->frame->getFrameTime();
        int currentFrame = this->statementTimeLine->getFrame();
        GLubyte alpha = Flash::execute(currentTime);
        this->loadingLabel->setOpacity(alpha);
        if (currentFrame == 1) {
            this->tutorialLabel->runAction(FadeIn::create(1.0f));
        }
        if (currentFrame == 300) {
            this->tutorialLabel->runAction(FadeOut::create(1.0f));
        }
        if (currentFrame == 450) {
            this->reset();
        }
        res.clear();
        this->frame->setFrameTime(0.01f);
        this->statementTimeLine->setFrame(1);
    }
}
void LoadingUILoadingState::reset() {
    Response res = ServiceGateway::getInstance()->request("service://loading/download")->get();
    std::string message = res.get<std::string>("message");
    res.clear();
    this->tutorialLabel->setString(message);
    this->frame->reset();
    this->statementTimeLine->reset();
}

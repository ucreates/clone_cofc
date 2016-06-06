//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "LogoUIShowState.h"
#include "SoundEffectAsset.h"
#include "UIAsset.h"
#include "Notifier.h"
#include "NotifyMessage.h"

LogoUIShowState::LogoUIShowState() {}

LogoUIShowState::~LogoUIShowState() {}

void LogoUIShowState::create() {
    SoundEffectAsset* se = (SoundEffectAsset*)this->owner->getAsset("jingle");
    se->play();
    std::function<void()> endFrameCallback = [this]() { Notifier::getInstance()->notify(NotifyMessage::Logo_Scene_Complete_State); };
    UIAsset* asset = (UIAsset*)this->owner->getAsset("ui");
    asset->play("show", endFrameCallback);
    return;
}

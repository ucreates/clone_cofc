//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "CannonBulletDestroyState.h"
// behaviour
#include "BehaviourStatus.h"
CannonBulletDestroyState::CannonBulletDestroyState() {}
CannonBulletDestroyState::~CannonBulletDestroyState() {}
void CannonBulletDestroyState::create() {
    BaseRenderAsset* asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    asset->hide();
    this->owner->getProperty()->setStatus(BehaviourStatus::COMPLETE);
    return;
}
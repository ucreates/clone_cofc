//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "MortarBulletDestroyState.h"
// notify
#include "Notifier.h"
#include "NotifyMessage.h"
// behaviour
#include "BehaviourStatus.h"
#include "GeographicDepth.h"
#include "MotarExplosionEffectBehaviour.h"
#include "BehaviourMapper.h"
MortarBulletDestroyState::MortarBulletDestroyState() {}
MortarBulletDestroyState::~MortarBulletDestroyState() {}
void MortarBulletDestroyState::create() {
    Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_Shake_State);
    BaseRenderAsset* asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    asset->hide();
    Transform transform = asset->getTransform();
    Position pos = Position(this->owner->goal->position, this->owner->goal->depth + GeographicDepth::EFFECT_DEPTH_RELATIVE_TO_NODE);
    MotarExplosionEffectBehaviour effect;
    effect.onCreate(this->owner->getLayer(), pos);
    this->owner->getProperty()->setStatus(BehaviourStatus::COMPLETE);
    return;
}
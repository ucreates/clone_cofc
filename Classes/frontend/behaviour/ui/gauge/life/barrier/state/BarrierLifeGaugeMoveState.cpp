//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BarrierLifeGaugeMoveState.h"

// notify
#include "Notifier.h"
#include "NotifyMessage.h"

// asset
#include "AnimatorAsset.h"
#include "Position.h"

BarrierLifeGaugeMoveState::BarrierLifeGaugeMoveState() { this->persistence = true; }

BarrierLifeGaugeMoveState::~BarrierLifeGaugeMoveState() {}

void BarrierLifeGaugeMoveState::create() {
    this->unitRenderAsset = (BaseRenderAsset*)this->owner->unit->getAsset("anime");
    this->lifeGuageRenderAsset = (AnimatorAsset*)this->owner->getAsset("anime");
    return;
}

void BarrierLifeGaugeMoveState::update(float delta) {
    Transform transform = this->unitRenderAsset->getTransform();
    Position pos = transform.getPosition();
    this->lifeGuageRenderAsset->transform(pos.x, pos.y, pos.zorder + 1);
    return;
}

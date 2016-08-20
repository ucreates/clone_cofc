//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BeaconEffectShowState.h"
#include "AnimatorAsset.h"
#include "GeographicDepth.h"
BeaconEffectShowState::BeaconEffectShowState() {}
BeaconEffectShowState::~BeaconEffectShowState() {}
void BeaconEffectShowState::create(Parameter* parameter) {
    GeographicNode* goal = parameter->get<GeographicNode*>("goalGeographicNode");
    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    std::function<void()> callback = [this]() {
        AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
        asset->hide();
    };
    asset->transform(goal, goal->depth + GeographicDepth::EFFECT_DEPTH_RELATIVE_TO_NODE);
    asset->play("show", callback, false);
    asset->show();
    return;
}

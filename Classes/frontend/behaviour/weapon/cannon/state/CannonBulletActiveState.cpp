//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "CannonBulletActiveState.h"
#include "GeographicDepth.h"
// vfx
#include "Move.h"
using namespace cocos2d;
CannonBulletActiveState::CannonBulletActiveState() { this->validator = new LayerRangeValidator(); }
CannonBulletActiveState::~CannonBulletActiveState() { CC_SAFE_DELETE(this->validator); }
void CannonBulletActiveState::create(Parameter* parameter) {
    GeographicNode* node = this->owner->start;
    this->asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    this->asset->transform(node->depth + GeographicDepth::WEAPON_DEPTH_RELATIVE_TO_NODE);
    Position pos = this->asset->getTransform().getPosition();
    Layer* layer = this->owner->getLayer();
    this->degree = parameter->get<float>("degree");
    this->frame->reset();
    this->validator->setProperty(pos, layer);
    this->asset->show();
    return;
}
void CannonBulletActiveState::update(float delta) {
    if (false == this->validator->isValid()) {
        this->owner->getStateMachine()->change("destroy");
        return;
    }
    Vec2 pos = this->asset->getTransform().getPosition().vector2d;
    pos = Move::execute(pos, this->degree, 40.0f);
    this->asset->transform(pos);
    this->frame->setFrame(1);
}
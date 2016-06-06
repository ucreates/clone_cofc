//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "WoodFenceHDestroyState.h"

// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"

// notify
#include "Notifier.h"
#include "NotifyMessage.h"

#include "DestroyEffectBehaviour.h"
#include "BehaviourMapper.h"
#include "SoundEffectAsset.h"
#include "ServiceGateway.h"
#include "Position.h"
#include "BarrierBehaviourType.h"

WoodFenceHDestroyState::WoodFenceHDestroyState() { this->destroyStrategy = ServiceGateway::getInstance()->request("service://barrier/destroy"); }

WoodFenceHDestroyState::~WoodFenceHDestroyState() {}

void WoodFenceHDestroyState::create() {
    this->complete = true;
    BaseRenderAsset* asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    asset->hide();

    Transform transform = asset->getTransform();
    Position pos = transform.getPosition();
    DestroyEffectBehaviour effect(this->owner->property);
    effect.onCreate(this->owner->getLayer(), pos);

    GeographicNode* node = this->owner->getGeographicNode();
    node->type = BarrierBehaviourType::None;

    int id = this->owner->getProperty()->getId();
    std::string barrierName = this->owner->getProperty()->getName();
    Parameter parameter;
    parameter.set<int>("id", id);
    parameter.set<std::string>("barrierName", barrierName);
    Response res = this->destroyStrategy->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    this->owner->getProperty()->setStatus(BehaviourStatus::COMPLETE);
    res.clear();
    return;
}
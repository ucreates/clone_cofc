//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "TurretDestroyState.h"
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
TurretDestroyState::TurretDestroyState() { this->destoryStrategy = ServiceGateway::getInstance()->request("service://barrier/destroy"); }
TurretDestroyState::~TurretDestroyState() {}
void TurretDestroyState::create() {
    this->complete = true;
    BaseRenderAsset* asset = (BaseRenderAsset*)this->owner->getAsset("anime");
    asset->hide();
    Transform transform = asset->getTransform();
    Position pos = transform.getPosition();
    DestroyEffectBehaviour effect(this->owner->property);
    effect.onCreate(this->owner->getLayer(), pos);
    GeographicNode* node = this->owner->getGeographicNode();
    GeographicGateway* gateway = GeographicGateway::getInstance();
    std::vector<GeographicNode*> nodeVector = gateway->find2x2ByAddress(node->address);
    for (std::vector<GeographicNode*>::iterator it = nodeVector.begin(); it != nodeVector.end(); it++) {
        GeographicNode* node = (*it);
        node->type = BarrierBehaviourType::None;
    }
    int id = this->owner->getProperty()->getId();
    std::string barrierName = this->owner->getProperty()->getName();
    Parameter parameter;
    parameter.set<int>("id", id);
    parameter.set<std::string>("barrierName", barrierName);
    Response res = this->destoryStrategy->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_Score_Update_State);
    bool showOverAllStar = res.get<bool>("showOverAllStar");
    if (false != showOverAllStar) {
        TOverAllTable record = res.get<TOverAllTable>("overAll");
        this->notifyOverAll(record);
    }
    res.clear();
    this->owner->getProperty()->setStatus(BehaviourStatus::COMPLETE);
    return;
}
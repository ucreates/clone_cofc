//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// behaviour
#include "BehaviourCollection.h"
#include "BehaviourMapper.h"
#include "BarrierBehaviourType.h"

// device
#include "ContinuousTouch.h"

// geographic
#include "GeographicGateway.h"
#include "GeographicDepth.h"

// notify
#include "Notifier.h"

// service
#include "ServiceGateway.h"
#include "Response.h"

using namespace cocos2d;

ContinuousTouch::ContinuousTouch() {}

ContinuousTouch::ContinuousTouch(cocos2d::Layer* layer) {
    this->timeLine = new TimeLine();
    this->enable = false;
    this->parentLayer = layer;
}

ContinuousTouch::~ContinuousTouch() { CC_SAFE_DELETE(this->timeLine); }

void ContinuousTouch::onBegan(std::vector<Point> touchPointVector) {
    if (false == this->enable || 0 == touchPointVector.size()) {
        return;
    }

    this->beganPoint = touchPointVector.at(0);
    this->enable = true;
    return;
}

void ContinuousTouch::onMove(std::vector<Point> touchPointVector) {
    if (false == this->enable || 0 == touchPointVector.size()) {
        return;
    }

    this->beganPoint = touchPointVector.at(0);
}

void ContinuousTouch::onEnd(std::vector<Point> touchPointVector) { this->enable = false; }

void ContinuousTouch::onExecute() {
    if (false == this->enable) {
        return;
    }

    int frame = this->timeLine->getFrame();
    if (false == this->enable || frame < ContinuousTouch::ENABLE_TOUCH_THRESHOLD_FRAME) {
        this->timeLine->setFrame(1);
        return;
    }

    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicNode* node = gateway->findByPosition(this->beganPoint);
    if (NULL == node || node->type != BarrierBehaviourType::None) {
        return;
    }

    Response res = ServiceGateway::getInstance()->request("service://resource/select")->get();
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        res.clear();
        return;
    }

    int selectUnitId = res.get<int>("selectUnitId");
    int selectUnitCount = res.get<int>("selectUnitCount");
    if (0 == selectUnitId || 0 == selectUnitCount) {
        res.clear();
        return;
    }

    if (false != this->firstTouch) {
        Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_Battle_Attack_State);
        this->firstTouch = false;
    }

    std::string selectUnitType = res.get<std::string>("selectUnitType");
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    BaseBehaviour* unit = collection->getUnitCache(selectUnitType);
    BehaviourMapper* mapper = BehaviourMapper::getInstance();
    mapper->addMappingList(unit, Position(this->beganPoint, GeographicDepth::UNIT_DEPTH));
    this->timeLine->reset();
    res.clear();
}
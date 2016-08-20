//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BarrierLifeGaugeShowState.h"
#include "ServiceGateway.h"
#include "Parameter.h"
#include "Response.h"
#include "UIAsset.h"
using namespace cocos2d;
using namespace cocos2d::ui;
BarrierLifeGaugeShowState::BarrierLifeGaugeShowState() { this->owner = owner; }
BarrierLifeGaugeShowState::~BarrierLifeGaugeShowState() {}
void BarrierLifeGaugeShowState::create() {
    int barrierId = this->owner->unit->getProperty()->getId();
    Parameter parameter;
    parameter.set<int>("barrierId", barrierId);
    Response res = ServiceGateway::getInstance()->request("service://barrier/damage")->get(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    float restHpPercentage = res.get<float>("restHpPercentage");
    UIAsset* asset = (UIAsset*)this->owner->getAsset("anime");
    LoadingBar* barrierLife = asset->findByName<LoadingBar*>("barrierLife");
    barrierLife->setPercent(restHpPercentage);
    asset->show();
    this->frame->reset();
    res.clear();
    return;
}
void BarrierLifeGaugeShowState::update(float delta) {
    float time = this->frame->getFrameTime();
    if (time > BarrierLifeGaugeShowState::CLOSE_TIME) {
        BaseRenderAsset* asset = (BaseRenderAsset*)this->owner->getAsset("anime");
        Node* node = asset->getNode();
        node->setVisible(false);
    }
    this->frame->setFrameTime(delta);
    return;
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "UnitLifeGaugeShowState.h"
#include "ServiceGateway.h"
#include "Parameter.h"
#include "Response.h"
#include "UIAsset.h"
using namespace cocos2d;
using namespace cocos2d::ui;
UnitLifeGaugeShowState::UnitLifeGaugeShowState() {}
UnitLifeGaugeShowState::~UnitLifeGaugeShowState() {}
void UnitLifeGaugeShowState::create() {
    int unitId = this->owner->unit->getProperty()->getId();
    Parameter parameter;
    parameter.set<int>("unitId", unitId);
    Response res = ServiceGateway::getInstance()->request("service://unit/damage")->get(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        res.clear();
        return;
    }
    float restHpPercentage = res.get<float>("restHpPercentage");
    UIAsset* asset = (UIAsset*)this->owner->getAsset("anime");
    LoadingBar* unitLife = asset->findByName<LoadingBar*>("unitLife");
    LoadingBar* unitLifeCrisis = asset->findByName<LoadingBar*>("unitLifeCrisis");
    unitLife->setPercent(restHpPercentage);
    unitLifeCrisis->setPercent(restHpPercentage);
    if (UnitLifeGaugeShowState::CRISIS_PERCENTAGE > restHpPercentage) {
        unitLife->setVisible(false);
        unitLifeCrisis->setVisible(true);
    }
    asset->show();
    this->frame->reset();
    res.clear();
    return;
}
void UnitLifeGaugeShowState::update(float delta) {
    float time = this->frame->getFrameTime();
    if (time > UnitLifeGaugeShowState::CLOSE_TIME) {
        BaseRenderAsset* asset = (BaseRenderAsset*)this->owner->getAsset("anime");
        Node* node = asset->getNode();
        node->setVisible(false);
    }
    this->frame->setFrameTime(delta);
    return;
}

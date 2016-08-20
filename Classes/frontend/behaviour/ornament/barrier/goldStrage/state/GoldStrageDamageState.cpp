//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "GoldStrageDamageState.h"
// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
// notify
#include "Notifier.h"
#include "NotifyMessage.h"
// asset
#include "AnimatorAsset.h"
#include "GoldStrageDamageEffectBehaviour.h"
#include "BehaviourMapper.h"
#include "ServiceGateway.h"
#include "Response.h"
#include "Position.h"
GoldStrageDamageState::GoldStrageDamageState() { this->damageStrategy = ServiceGateway::getInstance()->request("service://barrier/damage"); }
GoldStrageDamageState::~GoldStrageDamageState() {}
void GoldStrageDamageState::create(Parameter* parameter) {
    Response res = this->damageStrategy->update(parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    int restHp = res.get<int>("restHp");
    if (restHp <= 0) {
        this->owner->getStateMachine()->change("destroy", true);
    } else {
        float restHpPercentage = res.get<float>("restHpPercentage");
        AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
        if (0.0f < restHpPercentage && restHpPercentage <= 20.0f) {
            asset->pause(1);
        } else if (20.0f < restHpPercentage && restHpPercentage <= 40.0f) {
            asset->pause(2);
        } else if (40.0f < restHpPercentage && restHpPercentage <= 60.0f) {
            asset->pause(3);
        } else if (60.0f < restHpPercentage && restHpPercentage <= 80.0f) {
            asset->pause(4);
        } else if (80.0f < restHpPercentage && restHpPercentage <= 100.0f) {
            asset->pause(5);
        }
        INotify* notify = (INotify*)this->owner->lifeGuage;
        notify->onNotify(NotifyMessage::Behaviour_Barrier_Life_Show);
        Transform transform = asset->getTransform();
        Position pos = transform.getPosition();
        GoldStrageDamageEffectBehaviour effect;
        effect.onCreate(this->owner->getLayer(), pos);
    }
    res.clear();
    return;
}
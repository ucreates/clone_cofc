//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "MortarDamageState.h"
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
MortarDamageState::MortarDamageState() { this->damageStrategy = ServiceGateway::getInstance()->request("service://barrier/damage"); }
MortarDamageState::~MortarDamageState() {}
void MortarDamageState::create(Parameter* parameter) {
    Response res = this->damageStrategy->update(parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    int restHp = res.get<int>("restHp");
    if (restHp <= 0) {
        this->owner->getStateMachine()->change("destroy", true);
    } else {
        INotify* notifier = (INotify*)this->owner->lifeGuage;
        notifier->onNotify(NotifyMessage::Behaviour_Barrier_Life_Show);
    }
    res.clear();
    return;
}
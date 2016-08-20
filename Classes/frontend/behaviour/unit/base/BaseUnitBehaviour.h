//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseUnitBehaviour_h
#define BaseUnitBehaviour_h
// notify
#include "Parameter.h"
// service
#include "UnitBizLogic.h"
#include "BeaconEffectBehaviour.h"
#include "RayEffectBehaviour.h"
#include "UnitLifeGaugeBehaviour.h"
#include "ShadowEffectBehaviour.h"
class UnitLifeGaugeBehaviour;
class BaseUnitBehaviour : public BaseBehaviour {
   public:
    UnitLifeGaugeBehaviour* lifeGuage;
    RayEffectBehaviour* ray;
    BeaconEffectBehaviour* beacon;
    ShadowEffectBehaviour* shadow;
    BaseUnitBehaviour();
    virtual ~BaseUnitBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float time = 0.0f) override;
    void onCollision() override;
    BeaconEffectBehaviour* getBeacon();
    UnitLifeGaugeBehaviour* getLifeGuage();
};
#endif

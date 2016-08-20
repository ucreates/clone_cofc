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
#include "BaseUnitBehaviour.h"
#include "BehaviourCollection.h"
#include "RectCollider.h"
// peroperty
#include "UnitProperty.h"
#include "WeaponProperty.h"
// asset
#include "AnimatorAsset.h"
#include "TextureAsset.h"
// notify
#include "Notifier.h"
#include "ServiceGateway.h"
#include "Parameter.h"
using namespace cocos2d;
BaseUnitBehaviour::BaseUnitBehaviour() {
    this->beacon = new BeaconEffectBehaviour();
    this->collider = new RectCollider(this);
    this->lifeGuage = new UnitLifeGaugeBehaviour(this);
    this->ray = new RayEffectBehaviour();
    this->shadow = new ShadowEffectBehaviour(this);
}
BaseUnitBehaviour::~BaseUnitBehaviour() {
    CC_SAFE_DELETE(this->beacon);
    CC_SAFE_DELETE(this->collider);
    CC_SAFE_DELETE(this->lifeGuage);
    CC_SAFE_DELETE(this->ray);
    CC_SAFE_DELETE(this->shadow);
}
void BaseUnitBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;
    this->lifeGuage->onCreate(layer, position);
    this->ray->onCreate(layer, position);
    this->beacon->onCreate(layer, position);
}
void BaseUnitBehaviour::onUpdate(float delta) {
    this->lifeGuage->onUpdate(delta);
    this->beacon->onUpdate(delta);
    this->shadow->onUpdate(delta);
}
void BaseUnitBehaviour::onCollision() {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector("weapon");
    for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        WeaponProperty* wprop = (WeaponProperty*)behaviour->getProperty();
        if ("mortarBullet" != wprop->getName() && false != wprop->isEnemy() && BehaviourStatus::ACTIVE == wprop->getStatus() && this->collider->isHit(behaviour)) {
            int weaponId = wprop->getId();
            int unitId = this->property->getId();
            int barrierId = wprop->getOwnerId();
            Notifier::getInstance()->notify(weaponId, NotifyMessage::Behaviour_Weapon_Destroy);
            Parameter parameter;
            parameter.set<int>("unitId", unitId);
            parameter.set<int>("barrierId", barrierId);
            Response res = ServiceGateway::getInstance()->request("service://unit/damage")->update(&parameter);
            if (ServiceStatus::SUCCESS != res.getStatus()) {
                CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
                res.clear();
                return;
            }
            int restHp = res.get<int>("restHp");
            if (0 == restHp) {
                Notifier::getInstance()->notify(unitId, NotifyMessage::Behaviour_Unit_Dead);
            } else {
                this->lifeGuage->getStateMachine()->change("show");
            }
            res.clear();
            return;
        }
    }
    return;
}
BeaconEffectBehaviour* BaseUnitBehaviour::getBeacon() { return this->beacon; }
UnitLifeGaugeBehaviour* BaseUnitBehaviour::getLifeGuage() { return this->lifeGuage; }

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BaseBarrierBehaviour.h"
#include "BehaviourCollection.h"
#include "Notifier.h"
#include "WeaponProperty.h"
#include "ServiceGateway.h"
#include "Parameter.h"
#include "RectCollider.h"
#include "BarrierBehaviourType.h"
BaseBarrierBehaviour::BaseBarrierBehaviour() {
    this->lifeGuage = new BarrierLifeGaugeBehaviour(this);
    this->collider = new RectCollider(this);
    this->damageStrategy = ServiceGateway::getInstance()->request("service://barrier/damage");
}
BaseBarrierBehaviour::~BaseBarrierBehaviour() {
    CC_SAFE_DELETE(this->lifeGuage);
    CC_SAFE_DELETE(this->collider);
}
void BaseBarrierBehaviour::onCollision() {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector("weapon");
    for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        WeaponProperty* wprop = (WeaponProperty*)behaviour->getProperty();
        if ("mortarBullet" != wprop->getName() && false == wprop->isEnemy() && BehaviourStatus::ACTIVE == wprop->getStatus() && this->collider->isHit(behaviour)) {
            int weaponId = wprop->getId();
            int barrierId = this->property->getId();
            Notifier::getInstance()->notify(weaponId, NotifyMessage::Behaviour_Weapon_Destroy);
            Parameter parameter;
            parameter.set<int>("barrierId", barrierId);
            Response res = this->damageStrategy->get(&parameter);
            if (ServiceStatus::SUCCESS != res.getStatus()) {
                CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
                res.clear();
                return;
            }
            int restHp = res.get<int>("restHp");
            if (0 <= restHp) {
                int unitId = wprop->getOwnerId();
                parameter.set<int>("unitId", unitId);
                Notifier::getInstance()->notify(barrierId, NotifyMessage::Behaviour_Barrier_Damage, &parameter);
                this->lifeGuage->getStateMachine()->change("show");
            }
            res.clear();
            return;
        }
    }
    return;
}
std::vector<GeographicNode*> BaseBarrierBehaviour::getGeographicNodeVector() { return this->nodeVector; }
void BaseBarrierBehaviour::clearGeographicNodeVector() {
    for (std::vector<GeographicNode*>::iterator it = this->nodeVector.begin(); it != this->nodeVector.end(); it++) {
        GeographicNode* areaNode = (*it);
        areaNode->type = BarrierBehaviourType::None;
    }
    this->nodeVector.clear();
}
void BaseBarrierBehaviour::setGeographicNodeVector(std::vector<GeographicNode*> nodeVector) { this->nodeVector = nodeVector; }

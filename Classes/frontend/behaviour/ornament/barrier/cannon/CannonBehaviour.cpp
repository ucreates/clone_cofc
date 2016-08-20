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
#include "CannonBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "OrnamentProperty.h"
// asset
#include "AnimatorAsset.h"
#include "TextureAsset.h"
#include "SoundEffectAsset.h"
// notify
#include "Notifier.h"
// geographic
#include "GeographicDepth.h"
#include "Parameter.h"
#include "ServiceGateway.h"
#include "BarrierBehaviourType.h"
using namespace cocos2d;
CannonBehaviour::CannonBehaviour(GeographicNode* geographicNode) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/barrier/cannon", id));
    this->asset->add("texture", new TextureAsset("img/weapon/cannon/cnannon_stand.png"));
    this->geographicNode = geographicNode;
    this->property = new OrnamentProperty("cannon", id, "attack", 1, 1, 1);
    this->stateMachine = new FiniteStateMachine<CannonBehaviour>(this);
    this->stateMachine->add("attack", new CannonAttackState(id));
    this->stateMachine->add("search", new CannonSearchState());
    this->stateMachine->add("damage", new CannonDamageState());
    this->stateMachine->add("destroy", new CannonDestroyState());
    this->stateMachine->add("touchBegan", new CannonTouchBeganState());
    this->stateMachine->add("touchEnd", new CannonTouchEndState());
    this->stateMachine->stop();
    Notifier::getInstance()->add(this, this->property);
    Parameter parameter;
    parameter.set<int>("barrierId", id);
    parameter.set<int>("barrierType", BarrierBehaviourType::Cannon);
    Response res = ServiceGateway::getInstance()->request("service://barrier/create")->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    res.clear();
}
CannonBehaviour::~CannonBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void CannonBehaviour::onCreate(Layer* layer) {
    OrnamentProperty* opr = (OrnamentProperty*)this->property;
    int depth = this->geographicNode->depth + GeographicDepth::BARRIER_DEPTH_RELATIVE_TO_NODE * opr->getAddressScale()->x;
    this->onCreate(layer, depth);
}
void CannonBehaviour::onCreate(Layer* layer, int depth) {
    Position position = Position(this->geographicNode->position, depth);
    this->onCreate(layer, position);
    return;
}
void CannonBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;
    if (NULL != this->geographicNode) {
        std::vector<GeographicNode*> nodeVector;
        nodeVector.push_back(this->geographicNode);
        this->setGeographicNodeVector(nodeVector);
    }
    this->lifeGuage->onCreate(layer, position.zorder);
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position);
    anime->addLayer(layer, position.zorder);
    anime->pause();
    position.add(-1);
    BaseRenderAsset* texture = (BaseRenderAsset*)this->getAsset("texture");
    texture->transform(position);
    texture->addLayer(layer, position.zorder);
    this->stateMachine->change("search");
    this->stateMachine->play();
    return;
}
void CannonBehaviour::onUpdate(float delta) {
    this->lifeGuage->onUpdate(delta);
    this->stateMachine->update(delta);
}
void CannonBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (NULL == parameter) {
        return;
    }
    int barrierId = parameter->get<int>("barrierId");
    if (this->property->getId() != barrierId) {
        return;
    }
    if (notifyMessage == NotifyMessage::Behaviour_Barrier_Destroy) {
        this->stateMachine->change("destroy", true);
    } else if (notifyMessage == Behaviour_Barrier_Cannon_Search) {
        this->stateMachine->change("search", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Cannon_Attack) {
        this->stateMachine->change("attack", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Damage) {
        this->stateMachine->change("damage", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Touch_Began) {
        this->stateMachine->change("touchBegan", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Touch_End) {
        this->stateMachine->change("touchEnd", parameter);
    }
    this->stateMachine->play();
}

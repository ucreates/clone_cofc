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
#include "ElixirTankBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "OrnamentProperty.h"
// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"
// notify
#include "Notifier.h"
// geographic
#include "GeographicDepth.h"
#include "Parameter.h"
#include "ServiceGateway.h"
#include "BarrierBehaviourType.h"
using namespace cocos2d;
ElixirTankBehaviour::ElixirTankBehaviour(GeographicNode* geographicNode) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/barrier/elixirTank", id));
    this->geographicNode = geographicNode;
    this->property = new OrnamentProperty("elixirTank", id, "resource", 4, 6.0f, 4);
    this->stateMachine = new FiniteStateMachine<ElixirTankBehaviour>(this);
    this->stateMachine->add("destroy", new ElixirTankDestroyState());
    this->stateMachine->add("damage", new ElixirTankDamageState());
    this->stateMachine->add("touchBegan", new ElixirTankTouchBeganState());
    this->stateMachine->add("touchEnd", new ElixirTankTouchEndState());
    this->stateMachine->stop();
    Notifier::getInstance()->add(this, this->property);
    Parameter parameter;
    parameter.set<int>("barrierId", id);
    parameter.set<int>("barrierType", BarrierBehaviourType::ElixirTank);
    Response res = ServiceGateway::getInstance()->request("service://barrier/create")->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    res.clear();
}
ElixirTankBehaviour::~ElixirTankBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void ElixirTankBehaviour::onCreate(Layer* layer) {
    OrnamentProperty* oproperty = (OrnamentProperty*)this->property;
    int depth = this->geographicNode->depth + GeographicDepth::BARRIER_DEPTH_RELATIVE_TO_NODE * oproperty->getAddressScale()->x;
    this->onCreate(layer, depth);
}
void ElixirTankBehaviour::onCreate(Layer* layer, int depth) {
    Position position = Position(this->geographicNode->position, depth);
    this->onCreate(layer, position);
    return;
}
void ElixirTankBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;
    if (NULL != this->geographicNode) {
        GeographicGateway* gateway = GeographicGateway::getInstance();
        std::vector<GeographicNode*> nodeVector = gateway->find4x4ByAddress(this->geographicNode->address);
        this->setGeographicNodeVector(nodeVector);
    }
    this->lifeGuage->onCreate(layer, position.zorder);
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position, (OrnamentProperty*)this->property);
    anime->addLayer(layer, position.zorder);
    anime->pause(5);
    this->stateMachine->play();
    return;
}
void ElixirTankBehaviour::onUpdate(float delta) {
    this->lifeGuage->onUpdate(delta);
    this->stateMachine->update(delta);
}
void ElixirTankBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (NULL == parameter) {
        return;
    }
    int barrierId = parameter->get<int>("barrierId");
    if (this->property->getId() != barrierId) {
        return;
    }
    if (notifyMessage == NotifyMessage::Behaviour_Barrier_Destroy) {
        this->stateMachine->change("destroy", true);
    } else if (notifyMessage == NotifyMessage::Behaviour_Barrier_Damage) {
        this->stateMachine->change("damage", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Touch_Began) {
        this->stateMachine->change("touchBegan", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Touch_End) {
        this->stateMachine->change("touchEnd", parameter);
    }
    this->stateMachine->play();
}
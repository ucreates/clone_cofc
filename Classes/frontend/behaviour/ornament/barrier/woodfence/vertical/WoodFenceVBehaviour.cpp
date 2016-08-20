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
#include "WoodFenceVBehaviour.h"
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
WoodFenceVBehaviour::WoodFenceVBehaviour(GeographicNode* geographicNode) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/barrier/woodFence/vertical", id));
    this->geographicNode = geographicNode;
    this->property = new OrnamentProperty("woodFenceV", id, "wall", 1, 0.25f, 1);
    this->stateMachine = new FiniteStateMachine<WoodFenceVBehaviour>(this);
    this->stateMachine->add("destroy", new WoodFenceVDestroyState());
    this->stateMachine->add("damage", new WoodFenceVDamageState());
    this->stateMachine->add("touchBegan", new WoodFenceVTouchBeganState());
    this->stateMachine->add("touchEnd", new WoodFenceVTouchEndState());
    this->stateMachine->stop();
    Notifier::getInstance()->add(this, this->property);
    Parameter parameter;
    parameter.set<int>("barrierId", id);
    parameter.set<int>("barrierType", BarrierBehaviourType::WoodFenceV);
    Response res = ServiceGateway::getInstance()->request("service://barrier/create")->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    res.clear();
}
WoodFenceVBehaviour::~WoodFenceVBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void WoodFenceVBehaviour::onCreate(Layer* layer) {
    OrnamentProperty* oproperty = (OrnamentProperty*)this->property;
    int depth = this->geographicNode->depth + GeographicDepth::BARRIER_DEPTH_RELATIVE_TO_NODE * oproperty->getAddressScale()->x;
    this->onCreate(layer, depth);
}
void WoodFenceVBehaviour::onCreate(Layer* layer, int depth) {
    Position position = Position(this->geographicNode->position, depth);
    this->onCreate(layer, position);
    return;
}
void WoodFenceVBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;
    if (NULL != this->geographicNode) {
        std::vector<GeographicNode*> nodeVector;
        nodeVector.push_back(this->geographicNode);
        this->setGeographicNodeVector(nodeVector);
    }
    this->lifeGuage->onCreate(layer, position.zorder);
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->pause();
    anime->transform(position, (OrnamentProperty*)this->property);
    anime->addLayer(layer, position.zorder);
    this->stateMachine->play();
    return;
}
void WoodFenceVBehaviour::onUpdate(float delta) {
    this->lifeGuage->onUpdate(delta);
    this->stateMachine->update(delta);
}
void WoodFenceVBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (NULL == parameter) {
        return;
    }
    int barrierId = parameter->get<int>("barrierId");
    if (this->property->getId() != barrierId) {
        return;
    }
    if (notifyMessage == NotifyMessage::Behaviour_Barrier_Destroy) {
        this->stateMachine->change("destroy", true);
    } else if (notifyMessage == Behaviour_Barrier_Damage) {
        this->stateMachine->change("damage", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Touch_Began) {
        this->stateMachine->change("touchBegan", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Touch_End) {
        this->stateMachine->change("touchEnd", parameter);
    }
    this->stateMachine->play();
}
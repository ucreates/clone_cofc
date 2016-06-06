//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "MortarPauseState.h"

#include "BehaviourCollection.h"
#include "Distance.h"
#include "Position.h"

MortarPauseState::MortarPauseState() {}

MortarPauseState::~MortarPauseState() {}

void MortarPauseState::create() {
    this->asset = (AnimatorAsset*)this->owner->getAsset("anime");
    BaseUnitBehaviour* unit = this->search();
    if (NULL == unit) {
        this->enableSearch = false;
        return;
    }
    BaseRenderAsset* unitAsset = (BaseRenderAsset*)unit->getAsset("anime");
    Transform transform = unitAsset->getTransform();
    Position pos = transform.getPosition();
    GeographicGateway* gateway = GeographicGateway::getInstance();
    this->targetNode = gateway->findByPosition(pos.vector2d);
    if (NULL == this->targetNode) {
        this->enableSearch = false;
        return;
    }

    this->frame->reset();
    this->enableSearch = true;
    return;
}

void MortarPauseState::update(float delta) {
    if (false == this->enableSearch) {
        this->owner->getStateMachine()->change("pause");
        return;
    }

    if (MortarPauseState::SHOT_TIME < this->frame->getFrameTime() && NULL != this->targetNode) {
        Parameter parameter;
        parameter.set<GeographicNode*>("targetNode", this->targetNode);
        this->owner->getStateMachine()->change("attack", &parameter);
        return;
    }
    this->frame->setFrameTime(delta);
    return;
}

BaseUnitBehaviour* MortarPauseState::search() {
    BaseUnitBehaviour* ret = NULL;
    Transform ctrfm = this->asset->getTransform();
    Position cpos = ctrfm.getPosition();
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector("unit");
    for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        std::string type = behaviour->getProperty()->getType();
        BaseUnitBehaviour* unit = (BaseUnitBehaviour*)behaviour;
        BaseRenderAsset* asset = (BaseRenderAsset*)unit->getAsset("anime");
        Transform ttrfm = asset->getTransform();
        Position tpos = ttrfm.getPosition();
        int distance = Distance::create(cpos, tpos);
        if (distance < MortarPauseState::MOST_SHORTEST_DISTANCE) {
            ret = unit;
            break;
        }
    }
    return ret;
}
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "MortarAttackState.h"

// const
#include "Macro.h"

// behaviour
#include "BehaviourMapper.h"

// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"

// notify
#include "Notifier.h"
#include "NotifyMessage.h"

// asset
#include "AnimatorAsset.h"

// utility
#include "Random.h"
#include "BehaviourCollection.h"

MortarAttackState::MortarAttackState(int ownerId) { this->bullet = new MortarBulletBehaviour(NULL, NULL, ownerId, false); }

MortarAttackState::~MortarAttackState() {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    collection->addClearVector(this->bullet);
}

void MortarAttackState::create(Parameter* parameter) {
    this->targetNode = parameter->get<GeographicNode*>("targetNode");
    if (NULL == this->targetNode) {
        this->owner->getStateMachine()->change("pause");
        return;
    }

    std::function<void()> callback = [this]() {
        GeographicNode* start = this->owner->getGeographicNode();
        GeographicNode* goal = this->targetNode;
        this->bullet->setProperty(start, goal, false);
        BehaviourMapper::getInstance()->addMappingList(this->bullet, start->position, start->depth);
        this->owner->getStateMachine()->change("pause");
    };

    AnimatorAsset* asset = (AnimatorAsset*)this->owner->getAsset("anime");
    asset->play("attack", callback, false);
    return;
}
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "GraveBehaviour.h"

// behaviour
#include "GraveBehaviour.h"
#include "BehaviourIdGenerator.h"

// peroperty
#include "OrnamentProperty.h"

// asset
#include "AnimatorAsset.h"

// notify
#include "Notifier.h"

// geographic
#include "GeographicDepth.h"

using namespace cocos2d;

GraveBehaviour::GraveBehaviour(GeographicNode* geographicNode) {
    int id = BehaviourIdGenerator::getInstance()->getId();

    this->asset->add("anime", new AnimatorAsset("csb/animation/barrier/grave", id));
    this->geographicNode = geographicNode;
    this->property = new OrnamentProperty("grave", id, "other", 1, 1, 1);
}

GraveBehaviour::~GraveBehaviour() {}

void GraveBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;

    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position);
    anime->play("grave", false);
    anime->addLayer(layer, position.zorder);
}
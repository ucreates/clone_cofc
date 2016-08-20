//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BehaviourIdGenerator.h"
#include "GrassBehaviour.h"
GrassBehaviour::GrassBehaviour(GeographicNode* geographicNode) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->geographicNode = geographicNode;
    this->property = new OrnamentProperty("ground", id, "other", 1, 1, 1);
    this->stateMachine = new FiniteStateMachine<GrassBehaviour>(this);
    this->stateMachine->add("show", new GrassBehaviourShowState());
}
GrassBehaviour::~GrassBehaviour() {}
void GrassBehaviour::onCreate() {
    this->stateMachine->change("show", true);
    this->stateMachine->play();
}
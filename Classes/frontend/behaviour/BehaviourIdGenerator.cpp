//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include <cstddef>
#include "cocos2d.h"
#include "BehaviourIdGenerator.h"
BehaviourIdGenerator* BehaviourIdGenerator::instance = NULL;
BehaviourIdGenerator::BehaviourIdGenerator() { this->id = 0; }
BehaviourIdGenerator* BehaviourIdGenerator::getInstance() {
    if (NULL == BehaviourIdGenerator::instance) {
        BehaviourIdGenerator::instance = new BehaviourIdGenerator();
    }
    return BehaviourIdGenerator::instance;
}
int BehaviourIdGenerator::getId() {
    this->id++;
    return this->id;
}
void BehaviourIdGenerator::clear() { this->id = 0; }
void BehaviourIdGenerator::destroy() { CC_SAFE_DELETE(BehaviourIdGenerator::instance); }
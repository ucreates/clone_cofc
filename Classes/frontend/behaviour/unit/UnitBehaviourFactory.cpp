//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "UnitBehaviourFactory.h"
#include "BarbarianBehaviour.h"
#include "ArcherBehaviour.h"
#include "GiantBehaviour.h"
#include "WallBreakerBehaviour.h"
#include "GoblinBehaviour.h"
#include "UnitBehaviourType.h"

BaseUnitBehaviour* UnitBehaviourFactory::factoryMethod(int typeId) {
    BaseUnitBehaviour* unit = NULL;
    switch (typeId) {
        case UnitBehaviourType::Archer:
            unit = new ArcherBehaviour();
            break;
        case UnitBehaviourType::Barbarian:
            unit = new BarbarianBehaviour();
            break;
        case UnitBehaviourType::Giant:
            unit = new GiantBehaviour();
            break;
        case UnitBehaviourType::Goblin:
            unit = new GoblinBehaviour();
            break;
        case UnitBehaviourType::WallBreaker:
            unit = new WallBreakerBehaviour();
            break;
    }
    return unit;
}

BaseUnitBehaviour* UnitBehaviourFactory::factoryMethod(std::string typeName) {
    BaseUnitBehaviour* unit = NULL;
    if (typeName == "barbarian") {
        unit = new BarbarianBehaviour();
    } else if (typeName == "archer") {
        unit = new ArcherBehaviour();
    } else if (typeName == "giant") {
        unit = new GiantBehaviour();
    } else if (typeName == "goblin") {
        unit = new GoblinBehaviour();
    } else if (typeName == "wallbreaker") {
        unit = new WallBreakerBehaviour();
    }
    return unit;
}

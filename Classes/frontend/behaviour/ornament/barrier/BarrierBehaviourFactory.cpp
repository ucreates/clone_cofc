//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BarrierBehaviourFactory.h"
#include "BaseBarrierBehaviour.h"
#include "CannonBehaviour.h"
#include "TurretBehaviour.h"
#include "WoodFenceVBehaviour.h"
#include "WoodFenceHBehaviour.h"
#include "MortarBehaviour.h"
#include "GoldStrageBehaviour.h"
#include "ElixirTankBehaviour.h"
#include "BarrierBehaviourType.h"
BaseBarrierBehaviour* BarrierBehaviourFactory::factoryMethod(short mapTipType, GeographicNode* node) {
    BaseBarrierBehaviour* barrier = NULL;
    switch (mapTipType) {
        case BarrierBehaviourType::WoodFenceH:
            barrier = new WoodFenceHBehaviour(node);
            break;
        case BarrierBehaviourType::WoodFenceV:
            barrier = new WoodFenceVBehaviour(node);
            break;
        case BarrierBehaviourType::Cannon:
            barrier = new CannonBehaviour(node);
            break;
        case BarrierBehaviourType::Turret:
            barrier = new TurretBehaviour(node);
            break;
        case BarrierBehaviourType::Mortar:
            barrier = new MortarBehaviour(node);
            break;
        case BarrierBehaviourType::GoldStrage:
            barrier = new GoldStrageBehaviour(node);
            break;
        case BarrierBehaviourType::ElixirTank:
            barrier = new ElixirTankBehaviour(node);
            break;
    }
    return barrier;
}

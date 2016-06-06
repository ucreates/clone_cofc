//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// service
#include "UnitService.h"
#include "UnitCreateStrategy.h"
#include "UnitDamageStrategy.h"
#include "UnitMoveStrategy.h"

UnitService::UnitService() {
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("create", new UnitCreateStrategy()));
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("damage", new UnitDamageStrategy()));
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("move", new UnitMoveStrategy()));
}

UnitService::~UnitService() {}
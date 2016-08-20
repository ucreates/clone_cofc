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
#include "BattleService.h"
#include "BattlePreparationStrategy.h"
#include "BattleResultStrategy.h"
#include "BattleStatusStrategy.h"
BattleService::BattleService() {
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("preparation", new BattlePreparationStrategy()));
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("result", new BattleResultStrategy()));
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("status", new BattleStatusStrategy()));
}
BattleService::~BattleService() {}
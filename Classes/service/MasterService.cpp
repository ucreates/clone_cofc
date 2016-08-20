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
#include "MasterService.h"
#include "MasterCreateStrategy.h"
MasterService::MasterService() { this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("create", new MasterCreateStrategy())); }
MasterService::~MasterService() {}
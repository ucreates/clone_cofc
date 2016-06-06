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
#include "ResourceService.h"
#include "ResourceInfoStrategy.h"
#include "ResourceSelectStrategy.h"

ResourceService::ResourceService() {
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("info", new ResourceInfoStrategy()));
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("select", new ResourceSelectStrategy()));
}

ResourceService::~ResourceService() {}
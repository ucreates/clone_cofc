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
#include "BaseService.h"
BaseService::BaseService() {}
BaseService::~BaseService() {}
BaseStrategy* BaseService::create(std::string strategyName) {
    if (this->strategyMap.end() == this->strategyMap.find(strategyName)) {
        return NULL;
    }
    return this->strategyMap[strategyName];
}
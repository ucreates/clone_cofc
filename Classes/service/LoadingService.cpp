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
#include "LoadingService.h"
#include "LoadingDownloadStrategy.h"

LoadingService::LoadingService() { this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("download", new LoadingDownloadStrategy())); }

LoadingService::~LoadingService() {}
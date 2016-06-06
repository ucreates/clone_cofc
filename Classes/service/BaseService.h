//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseService_h
#define BaseService_h

// stl
#include <map>

// service
#include "BaseStrategy.h"

class BaseService {
   public:
    BaseService();
    virtual ~BaseService();
    BaseStrategy* create(std::string strategyName);

   protected:
    std::map<std::string, BaseStrategy*> strategyMap;
};
#endif

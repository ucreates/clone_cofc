//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ResourceSelectStrategy_h
#define ResourceSelectStrategy_h

// service
#include "BaseStrategy.h"

class ResourceSelectStrategy : public BaseStrategy {
   public:
    ResourceSelectStrategy();
    virtual ~ResourceSelectStrategy();
    Response get(Parameter* parameter = NULL) override;
    Response update(Parameter* parameter = NULL) override;
};

#endif

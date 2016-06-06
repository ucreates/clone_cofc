//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef MasterCreateStrategy_h
#define MasterCreateStrategy_h

// service
#include "BaseStrategy.h"

class MasterCreateStrategy : public BaseStrategy {
   public:
    MasterCreateStrategy();
    virtual ~MasterCreateStrategy();
    Response update(Parameter* parameter = NULL) override;
};

#endif

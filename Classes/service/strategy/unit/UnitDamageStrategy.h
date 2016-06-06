//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef UnitDamageStrategy_h
#define UnitDamageStrategy_h

// service
#include "BaseStrategy.h"

class UnitDamageStrategy : public BaseStrategy {
   public:
    UnitDamageStrategy();
    virtual ~UnitDamageStrategy();
    Response get(Parameter* parameter = NULL) override;
    Response update(Parameter* parameter = NULL) override;
};

#endif

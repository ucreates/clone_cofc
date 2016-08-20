//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UnitCreateStrategy_h
#define UnitCreateStrategy_h
// service
#include "BaseStrategy.h"
class UnitCreateStrategy : public BaseStrategy {
   public:
    UnitCreateStrategy();
    virtual ~UnitCreateStrategy();
    Response update(Parameter* parameter = NULL) override;
};
#endif

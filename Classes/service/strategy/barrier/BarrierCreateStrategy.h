//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarrierCreateStrategy_h
#define BarrierCreateStrategy_h
// service
#include "BaseStrategy.h"
class BarrierCreateStrategy : public BaseStrategy {
   public:
    BarrierCreateStrategy();
    virtual ~BarrierCreateStrategy();
    Response update(Parameter* parameter = NULL) override;
};
#endif

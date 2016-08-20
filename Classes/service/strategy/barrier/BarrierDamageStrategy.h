//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarrierDamageStrategy_h
#define BarrierDamageStrategy_h
// service
#include "BaseStrategy.h"
class BarrierDamageStrategy : public BaseStrategy {
   public:
    BarrierDamageStrategy();
    virtual ~BarrierDamageStrategy();
    Response get(Parameter* parameter = NULL) override;
    Response update(Parameter* parameter = NULL) override;
};
#endif

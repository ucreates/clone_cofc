//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarrierDestroyStrategy_h
#define BarrierDestroyStrategy_h
// service
#include "BaseStrategy.h"
class BarrierDestroyStrategy : public BaseStrategy {
   public:
    BarrierDestroyStrategy();
    virtual ~BarrierDestroyStrategy();
    Response update(Parameter* parameter = NULL) override;
    Response clear(Parameter* parameter = NULL) override;
};
#endif

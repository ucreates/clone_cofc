//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UnitMoveStrategy_h
#define UnitMoveStrategy_h
// service
#include "BaseStrategy.h"
class UnitMoveStrategy : public BaseStrategy {
   public:
    UnitMoveStrategy();
    virtual ~UnitMoveStrategy();
    Response get(Parameter* parameter = NULL) override;
    Response update(Parameter* parameter = NULL) override;
    Response clear(Parameter* parameter = NULL) override;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattleResultStrategy_h
#define BattleResultStrategy_h

// service
#include "BaseStrategy.h"

class BattleResultStrategy : public BaseStrategy {
   public:
    BattleResultStrategy();
    virtual ~BattleResultStrategy();
    Response get(Parameter* parameter = NULL) override;
};

#endif

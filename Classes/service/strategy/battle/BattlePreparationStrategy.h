//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattlePreparationStrategy_h
#define BattlePreparationStrategy_h

// service
#include "BaseStrategy.h"

class BattlePreparationStrategy : public BaseStrategy {
   public:
    BattlePreparationStrategy();
    virtual ~BattlePreparationStrategy();
    Response get(Parameter* parameter = NULL) override;
    Response update(Parameter* parameter = NULL) override;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef MultiConditionExpression_h
#define MultiConditionExpression_h

// stl
#include <vector>

// service
#include "BaseExpression.h"
#include "ConditionExpression.h"

class MultiConditionExpression : public BaseExpression {
   public:
    MultiConditionExpression();
    virtual ~MultiConditionExpression();
    std::vector<ConditionExpression> getConditionExpression();
    void addCondition(ConditionExpression condition);

   protected:
    std::vector<ConditionExpression> conditionVector;
};

#endif

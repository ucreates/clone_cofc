//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ConditionExpression_h
#define ConditionExpression_h
// stl
#include <string>
// service
#include "BaseFieldSchema.h"
#include "BaseExpression.h"
class ConditionExpression : public BaseExpression {
   public:
    ConditionExpression();
    ConditionExpression(std::string fieldName, std::string comparisonOperator, BaseFieldSchema* field);
    virtual ~ConditionExpression();
    std::string fieldName;
    std::string comparisonOperator;
    BaseFieldSchema* field;
};
#endif

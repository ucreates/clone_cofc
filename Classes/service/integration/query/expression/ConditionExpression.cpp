//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// service
#include "ConditionExpression.h"
ConditionExpression::ConditionExpression() : fieldName(""), comparisonOperator("") {}
ConditionExpression::~ConditionExpression() {}
ConditionExpression::ConditionExpression(std::string fieldName, std::string comparisonOperator, BaseFieldSchema* field) {
    this->fieldName = fieldName;
    this->comparisonOperator = comparisonOperator;
    this->field = field;
    this->expressiontType = "condition";
}

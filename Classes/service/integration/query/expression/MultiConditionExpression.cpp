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
#include "MultiConditionExpression.h"
MultiConditionExpression::MultiConditionExpression() {}
MultiConditionExpression::~MultiConditionExpression() {}
std::vector<ConditionExpression> MultiConditionExpression::getConditionExpression() { return this->conditionVector; }
void MultiConditionExpression::addCondition(ConditionExpression condition) { this->conditionVector.push_back(condition); }

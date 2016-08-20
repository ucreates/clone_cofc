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
#include "OrderByExpression.h"
OrderByExpression::OrderByExpression() { this->expressiontType = "orderby"; }
OrderByExpression::OrderByExpression(std::string orderFieldSchemaName, OrderByExpression::OrderType orderType) {
    this->orderFieldSchemaName = orderFieldSchemaName;
    this->orderType = orderType;
    this->expressiontType = "orderby";
}
OrderByExpression::~OrderByExpression() {}
OrderByExpression::OrderType OrderByExpression::getOrderType() { return this->orderType; }
std::string OrderByExpression::getOrderFieldSchemaName() { return this->orderFieldSchemaName; }
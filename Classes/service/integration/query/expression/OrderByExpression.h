//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef OrderByExpression_h
#define OrderByExpression_h

// service
#include "BaseExpression.h"

class OrderByExpression : public BaseExpression {
   public:
    enum OrderType {
        Asc = 0x00,
        Desc = 0x01,
    };

    OrderByExpression();
    OrderByExpression(std::string orderFieldSchemaName, OrderByExpression::OrderType orderType);
    virtual ~OrderByExpression();
    OrderByExpression::OrderType getOrderType();
    std::string getOrderFieldSchemaName();

   private:
    OrderByExpression::OrderType orderType;
    std::string orderFieldSchemaName;
};

#endif

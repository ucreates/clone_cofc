//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LimitExpression_h
#define LimitExpression_h
// service
#include "BaseExpression.h"
class LimitExpression : public BaseExpression {
   public:
    LimitExpression();
    LimitExpression(int limit);
    virtual ~LimitExpression();
    int getLimit();
   private:
    int limit;
};
#endif

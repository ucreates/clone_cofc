//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef OrExpression_h
#define OrExpression_h
// service
#include "MultiConditionExpression.h"
class OrExpression : public MultiConditionExpression {
   public:
    OrExpression();
    virtual ~OrExpression();
};
#endif

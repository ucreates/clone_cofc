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
#include "LimitExpression.h"

LimitExpression::LimitExpression() {
    this->expressiontType = "limit";
    this->limit = 0;
}

LimitExpression::LimitExpression(int limit) {
    this->expressiontType = "limit";
    this->limit = limit;
}

LimitExpression::~LimitExpression() {}

int LimitExpression::getLimit() { return this->limit; }

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseStrategy_h
#define BaseStrategy_h

// cocos2d
#include "cocos2d.h"

// debug
#include "Macro.h"

// service
#include "Parameter.h"
#include "Response.h"

class BaseStrategy {
   public:
    BaseStrategy();
    virtual ~BaseStrategy();
    virtual Response load(Parameter* parameter = NULL);
    virtual Response get(Parameter* parameter = NULL);
    virtual Response request(Parameter* parameter = NULL);
    virtual Response update(Parameter* parameter = NULL);
    virtual Response clear(Parameter* parameter = NULL);
};

#endif

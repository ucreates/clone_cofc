//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseAssembler_h
#define BaseAssembler_h

// service
#include "BaseTable.h"

template <class T>
class BaseAssembler {
   public:
    BaseAssembler();
    virtual ~BaseAssembler();
    virtual std::vector<T> writeToVector();
};

#endif

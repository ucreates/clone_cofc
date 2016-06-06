//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef INotify_h
#define INotify_h

#include "NotifyMessage.h"
#include "Parameter.h"

class INotify {
   public:
    INotify() {}

    virtual ~INotify() {}
    int id;
    std::string type;
    virtual void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) = 0;
};

#endif

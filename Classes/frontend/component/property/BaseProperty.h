//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseProperty_h
#define BaseProperty_h
#include <string>
#include "BehaviourStatus.h"
class BaseProperty {
   public:
    BaseProperty();
    virtual ~BaseProperty();
    std::string getName();
    std::string getType();
    int getId();
    BehaviourStatus getStatus();
    void setStatus(BehaviourStatus status);
   protected:
    std::string name;
    std::string type;
    int id;
    BehaviourStatus status;
};
#endif

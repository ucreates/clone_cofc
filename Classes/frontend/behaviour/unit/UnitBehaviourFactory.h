//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include <string>
#include "BaseUnitBehaviour.h"
#ifndef UnitBehaviourFactory_h
#define UnitBehaviourFactory_h
class UnitBehaviourFactory {
   public:
    static BaseUnitBehaviour* factoryMethod(int typeId);
    static BaseUnitBehaviour* factoryMethod(std::string typeName);
};
#endif
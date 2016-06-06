//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BarrierBehaviourFactory_h
#define BarrierBehaviourFactory_h

#include "GeographicNode.h"
#include "BaseBarrierBehaviour.h"

class BarrierBehaviourFactory {
   public:
    static BaseBarrierBehaviour* factoryMethod(short mapTipType, GeographicNode* node);
};

#endif
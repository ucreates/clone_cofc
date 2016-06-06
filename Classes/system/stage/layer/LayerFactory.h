//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LayerFactory_h
#define LayerFactory_h
#include "cocos2d.h"

class LayerFactory {
   public:
    static cocos2d::Layer* factoryMethod(int layerId);
};

#endif

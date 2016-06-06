//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LoadingLayerBuilder_h
#define LoadingLayerBuilder_h

#include "BaseLayerBuilder.h"

class LoadingLayerBuilder : public BaseLayerBuilder {
   public:
    LoadingLayerBuilder();
    ~LoadingLayerBuilder();
    void build() override;
};

#endif

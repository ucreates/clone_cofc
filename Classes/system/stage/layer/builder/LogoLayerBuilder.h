//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LogoLayerBuilder_h
#define LogoLayerBuilder_h
#include "BaseLayerBuilder.h"
class LogoLayerBuilder : public BaseLayerBuilder {
   public:
    LogoLayerBuilder();
    ~LogoLayerBuilder();
    void build() override;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LayerRangeValidator_h
#define LayerRangeValidator_h
// cocos2d
#include "cocos2d.h"
// entity
#include "Position.h"
// validator
#include "BaseValidator.h"
class LayerRangeValidator : public BaseValidator {
   public:
    LayerRangeValidator();
    ~LayerRangeValidator();
    bool isValid() override;
    void setProperty(Position position, cocos2d::Layer* layer);
   private:
    Position position;
    cocos2d::Layer* layer;
};
#endif

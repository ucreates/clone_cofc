//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleLayerBuilder_h
#define BattleLayerBuilder_h
// cocos2d
#include "cocos2d.h"
// builder
#include "BaseLayerBuilder.h"
class BaseLayer;
class BattleLayerBuilder : public BaseLayerBuilder {
   public:
    BattleLayerBuilder();
    ~BattleLayerBuilder();
    BattleLayerBuilder* setUnitLayer(cocos2d::Layer* unitLayer);
    BattleLayerBuilder* setMap(std::string mapDataFileName);
    void build() override;
   private:
    std::string mapDataFileName;
    cocos2d::Layer* unitLayer;
};
#endif

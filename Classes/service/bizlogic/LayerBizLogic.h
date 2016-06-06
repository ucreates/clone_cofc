//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LayerBizLogic_h
#define LayerBizLogic_h
// cocos2d
#include "cocos2d.h"

// service
#include "BaseBizLogic.h"

class LayerBizLogic : public BaseBizLogic {
   public:
    LayerBizLogic();
    int getLayerId();
    void setLayerId(int layerId);
    cocos2d::Layer* getLayer();
    cocos2d::Layer* getLayer(int layerId);
    void setLayer(cocos2d::Layer* layer);
    void setLayer(int layerId, cocos2d::Layer* layer);
};

#endif
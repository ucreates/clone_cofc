//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseLayerBuilder_h
#define BaseLayerBuilder_h
// stl
#include <string>
#include <map>
#include <vector>
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseBehaviour.h"
// layer
#include "BaseLayer.h"
// touch
#include "BaseTouch.h"
class BaseLayer;
class BaseLayerBuilder {
   public:
    BaseLayerBuilder();
    virtual ~BaseLayerBuilder();
    BaseLayerBuilder* setDepthView(bool enableDepthView);
    BaseLayerBuilder* setProperty(std::string name);
    BaseLayerBuilder* setRootLayer(BaseLayer* rootLayer);
    BaseLayerBuilder* setUILayer(cocos2d::Layer* uiLayer);
    BaseLayerBuilder* setFieldOfView(float fov);
    BaseLayerBuilder* setBGMAsset(std::string soundName);
    BaseLayerBuilder* setSEAsset(std::string soundName);
    BaseLayerBuilder* setBackGround(BaseBehaviour* behaviour);
    BaseLayerBuilder* setUI(BaseBehaviour* behaviour);
    BaseLayerBuilder* setTouch(std::string touchName, BaseTouch* touch);
    BaseLayerBuilder* setTouchHandler(std::string handlerName, std::function<void(const std::vector<cocos2d::Touch*>&, cocos2d::Event*)> touchCallBack);
    virtual void build();
   protected:
    float fov;
    BaseLayer* rootLayer;
    cocos2d::Layer* uiLayer;
    bool enableDepthView;
    std::map<std::string, std::function<void(const std::vector<cocos2d::Touch*>&, cocos2d::Event*)>> touchEventHandlerMap;
};
#endif

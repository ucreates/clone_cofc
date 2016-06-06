//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseLayer_h
#define BaseLayer_h

#include "cocos2d.h"

// layer
#include "BaseLayerBuilder.h"

// property
#include "BaseProperty.h"

// touch
#include "BaseTouch.h"

// vfx
#include "TimeLine.h"

class BaseLayerBuilder;

class BaseLayer : public cocos2d::Layer {
    friend BaseLayerBuilder;

   public:
    static const int UI_LAYER_TAG = 1;
    static const int NODE_LAYER_TAG = 0;
    BaseLayer();
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
    void onExitTransitionDidStart() override;
    void onExit() override;
    void destroy();

   protected:
    std::map<std::string, BaseTouch*> touchMap;
    TimeLine* timeLine;
    BaseProperty* property;
    bool enableInput;
    bool transition;
};

#endif

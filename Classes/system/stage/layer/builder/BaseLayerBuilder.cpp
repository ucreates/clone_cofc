//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// behaviour
#include "BehaviourIdGenerator.h"
#include "BehaviourCollection.h"

// builder
#include "BaseLayerBuilder.h"

// cocos2d
#include "cocos2d.h"

// property
#include "LayerProperty.h"

// sound
#include "SoundAssetCollection.h"
#include "SoundEffectAsset.h"
#include "BGMAsset.h"

using namespace cocos2d;

BaseLayerBuilder::BaseLayerBuilder() : fov(1.0f), enableDepthView(false), rootLayer(NULL) {
    FileUtils::getInstance()->addSearchPath("img");
    FileUtils::getInstance()->addSearchPath("csb");
    FileUtils::getInstance()->addSearchPath("particle");
    FileUtils::getInstance()->addSearchPath("map");
    FileUtils::getInstance()->addSearchPath("sound");
    FileUtils::getInstance()->addSearchPath("config");
}

BaseLayerBuilder::~BaseLayerBuilder() {}

BaseLayerBuilder* BaseLayerBuilder::setDepthView(bool enableDepthView) {
    this->enableDepthView = enableDepthView;
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setRootLayer(BaseLayer* rootLayer) {
    this->rootLayer = rootLayer;
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setUILayer(Layer* uiLayer) {
    this->uiLayer = uiLayer;
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setProperty(std::string name) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->rootLayer->property = new LayerProperty(name, id);
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setFieldOfView(float fov) {
    this->fov = fov;
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setSEAsset(std::string seFilePath) {
    SoundAssetCollection* sai = SoundAssetCollection::getInstance();
    if (NULL == sai->getSEAsset(seFilePath)) {
        sai->setSEAsset(seFilePath, new SoundEffectAsset(seFilePath));
    }
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setBGMAsset(std::string bgmFilePath) {
    SoundAssetCollection* sai = SoundAssetCollection::getInstance();
    if (NULL == sai->getBGMAsset(bgmFilePath)) {
        sai->setBGMAsset(bgmFilePath, new BGMAsset(bgmFilePath));
    }
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setBackGround(BaseBehaviour* behaviour) {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    collection->add(behaviour);
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setUI(BaseBehaviour* behaviour) {
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    collection->add(behaviour);
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setTouch(std::string touchName, BaseTouch* touch) {
    if (this->rootLayer->touchMap.end() == this->rootLayer->touchMap.find(touchName)) {
        this->rootLayer->touchMap.insert(std::map<std::string, BaseTouch*>::value_type(touchName, touch));
    }
    return this;
}

BaseLayerBuilder* BaseLayerBuilder::setTouchHandler(std::string handlerName, std::function<void(const std::vector<Touch*>&, Event*)> touchCallBack) {
    if (this->touchEventHandlerMap.end() == this->touchEventHandlerMap.find(handlerName)) {
        this->touchEventHandlerMap.insert(std::map<std::string, std::function<void(const std::vector<Touch*>&, Event*)>>::value_type(handlerName, touchCallBack));
    }
    return this;
}

void BaseLayerBuilder::build() {
    this->rootLayer->addChild(uiLayer, 1, BaseLayer::UI_LAYER_TAG);

    EventListenerTouchAllAtOnce* listener = EventListenerTouchAllAtOnce::create();
    listener->setEnabled(true);

    for (std::map<std::string, std::function<void(const std::vector<Touch*>&, Event*)>>::iterator it = this->touchEventHandlerMap.begin(); it != this->touchEventHandlerMap.end(); ++it) {
        if ("touchBegan" == it->first) {
            listener->onTouchesBegan = it->second;
        } else if ("touchMove" == it->first) {
            listener->onTouchesMoved = it->second;
            listener->onTouchesCancelled = it->second;
        } else if ("touchEnd" == it->first) {
            listener->onTouchesEnded = it->second;
        }
    }
    EventDispatcher* dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this->rootLayer);
    return;
}
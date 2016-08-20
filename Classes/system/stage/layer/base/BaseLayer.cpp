//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "cocos2d.h"
// layer
#include "BaseLayer.h"
// behaviour
#include "BehaviourCollection.h"
#include "BehaviourIdGenerator.h"
#include "BehaviourMapper.h"
// command
#include "CommandGateway.h"
// geopgraphy
#include "GeographicGateway.h"
// notifier
#include "Notifier.h"
// service
#include "CommunicationGateway.h"
#include "DataBase.h"
#include "ServiceGateway.h"
// sound
#include "SoundAssetCollection.h"
using namespace cocos2d;
BaseLayer::BaseLayer() {
    this->enableInput = false;
    this->timeLine = new TimeLine();
    this->transition = false;
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyReleased = CC_CALLBACK_2(BaseLayer::onKeyReleased, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    BehaviourIdGenerator::getInstance();
    BehaviourCollection::getInstance();
    BehaviourMapper::getInstance();
    Notifier::getInstance();
    SoundAssetCollection::getInstance();
    CommandGateway::getInstance();
    CommunicationGateway::getInstance();
    ServiceGateway::getInstance();
    DataBase::getInstance();
}
void BaseLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    CCLOG("onKeyReleased");
    if (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE) {
        this->destroy();
    }
    return;
}
void BaseLayer::onExitTransitionDidStart() {
    this->transition = true;
    CC_SAFE_DELETE(this->timeLine);
    CC_SAFE_DELETE(this->property);
    Layer::onExitTransitionDidStart();
}
void BaseLayer::onExit() {
    if (false == this->transition) {
        this->destroy();
    }
    Layer::onExit();
}
void BaseLayer::destroy() {
    CC_SAFE_DELETE(this->timeLine);
    CC_SAFE_DELETE(this->property);
    BehaviourIdGenerator::destroy();
    BehaviourCollection::destroy();
    BehaviourMapper::destroy();
    GeographicGateway::destroy();
    Notifier::destroy();
    SoundAssetCollection::destroy();
    CommandGateway::destroy();
    CommunicationGateway::destroy();
    ServiceGateway::destroy();
    DataBase::destroy();
    Director::getInstance()->end();
}
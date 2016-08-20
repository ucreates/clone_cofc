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
#include "BattleBackGroundBehaviour.h"
#include "BattleUIBehaviour.h"
// layer
#include "BattleLayer.h"
#include "BattleLayerBuilder.h"
// math
#include "Random.h"
// notifier
#include "Notifier.h"
// sound
#include "SoundAssetCollection.h"
// touch
#include "ContinuousTouch.h"
#include "PinchTouch.h"
#include "SwipeTouch.h"
using namespace cocos2d;
bool BattleLayer::init() {
    if (false == Layer::init()) {
        return false;
    }
    Layer* unitLayer = Layer::create();
    Layer* uiLayer = Layer::create();
    std::string mapList[2] = {"map1.map", "map2.map"};
    int index = Random::create(10);
    std::string mapFileName = "";
    if (0 == index % 2) {
        mapFileName = mapList[0];
    } else {
        mapFileName = mapList[1];
    }
    BattleLayerBuilder builder;
    builder.setMap(mapFileName)
        ->setUnitLayer(unitLayer)
        ->setRootLayer(this)
        ->setUILayer(uiLayer)
        ->setBackGround(new BattleBackGroundBehaviour())
        ->setUI(new BattleUIBehaviour())
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        ->setBGMAsset("sound/bgm/combat_music.ogg")
        ->setBGMAsset("sound/bgm/combat_planning_music.ogg")
        ->setBGMAsset("sound/bgm/winwinwin.ogg")
        ->setBGMAsset("sound/bgm/battle_lost_02.ogg")
#else
        ->setBGMAsset("sound/bgm/combat_music.mp3")
        ->setBGMAsset("sound/bgm/combat_planning_music.mp3")
        ->setBGMAsset("sound/bgm/winwinwin.mp3")
        ->setBGMAsset("sound/bgm/battle_lost_02.mp3")
#endif
        ->setSEAsset("sound/se/barb_deploy_11v2.mp3")
        ->setSEAsset("sound/se/barb_deploy_11v3.mp3")
        ->setSEAsset("sound/se/barbarian_sword_swing_hit_14.mp3")
        ->setSEAsset("sound/se/barbarian_sword_swing_hit_14v2.mp3")
        ->setSEAsset("sound/se/barbarian_sword_swing_hit_14v3.mp3")
        ->setSEAsset("sound/se/archer_deploy_09v2.mp3")
        ->setSEAsset("sound/se/archer_deploy_09v3.mp3")
        ->setSEAsset("sound/se/archer_queen_attack_01.mp3")
        ->setSEAsset("sound/se/archer_queen_attack_02.mp3")
        ->setSEAsset("sound/se/giant_deploy_04v2.mp3")
        ->setSEAsset("sound/se/giant_deploy_04v3.mp3")
        ->setSEAsset("sound/se/giant_attack_05.mp3")
        ->setSEAsset("sound/se/giant_attack_06.mp3")
        ->setSEAsset("sound/se/giant_attack_hit_01.mp3")
        ->setSEAsset("sound/se/giant_attack_hit_02.mp3")
        ->setSEAsset("sound/se/goblin_deploy_14v2.mp3")
        ->setSEAsset("sound/se/goblin_deploy_14v3.mp3")
        ->setSEAsset("sound/se/gob_attack_01.mp3")
        ->setSEAsset("sound/se/gob_attack_02.mp3")
        ->setSEAsset("sound/se/gob_attack_03.mp3")
        ->setSEAsset("sound/se/wall_breaker_attack_01.mp3")
        ->setSEAsset("sound/se/wall_place_01.mp3")
        ->setSEAsset("sound/se/archer_tower_pick_01.mp3")
        ->setSEAsset("sound/se/building_destroyed_01.mp3")
        ->setSEAsset("sound/se/mortar_fire_02_with_fall.mp3")
        ->setSEAsset("sound/se/cannon_08.mp3")
        ->setTouch("continuous", new ContinuousTouch(unitLayer))
        ->setTouch("pinch", new PinchTouch(unitLayer, BattleLayer::DEFAULT_FIELD_OF_VIEW))
        ->setTouch("swipe", new SwipeTouch(unitLayer, BattleLayer::DEFAULT_FIELD_OF_VIEW))
        ->setTouchHandler("touchBegan", CC_CALLBACK_2(BattleLayer::onTouchesBegan, this))
        ->setTouchHandler("touchMove", CC_CALLBACK_2(BattleLayer::onTouchesMoved, this))
        ->setTouchHandler("touchEnd", CC_CALLBACK_2(BattleLayer::onTouchesEnded, this))
        ->setProperty("battle")
        ->setFieldOfView(BattleLayer::FIRST_FIELD_OF_VIEW)
        ->build();
    return true;
}
void BattleLayer::update(float delta) { this->stateMachine->update(delta); }
void BattleLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event* event) {
    if (false == this->enableInput) {
        return;
    }
    if (BaseTouch::SINGLE_TOUCH_COUNT == touches.size()) {
        this->touchMap["continuous"]->setEnableTouch(true);
        this->touchMap["swipe"]->setEnableTouch(true);
        Touch* touch = touches.at(0);
        Vec2 worldTouchPoint = touch->getLocation();
        Layer* unitLayer = (Layer*)this->getChildByTag(BaseLayer::NODE_LAYER_TAG);
        Vec2 nodeTouchPoint = unitLayer->convertToNodeSpace(worldTouchPoint);
        std::vector<Point> touchPointVector;
        touchPointVector.push_back(nodeTouchPoint);
        this->touchMap["continuous"]->onBegan(touchPointVector);
        touchPointVector.clear();
        touchPointVector.push_back(worldTouchPoint);
        this->touchMap["swipe"]->onBegan(touchPointVector);
        this->touchMap["continuous"]->setPreviousTouch(touch);
        this->touchMap["swipe"]->setPreviousTouch(touch);
        Touch* previousTouch = this->touchMap["pinch"]->getPreviousTouch();
        if (NULL == previousTouch) {
            this->touchMap["pinch"]->setPreviousTouch(touch);
            this->touchMap["pinch"]->setEnableTouch(false);
        } else {
            Touch* touch = previousTouch;
            Vec2 worldTouchPoint1 = touch->getLocation();
            touch = touches.at(0);
            Vec2 worldTouchPoint2 = touch->getLocation();
            std::vector<Point> touchPointVector;
            touchPointVector.push_back(worldTouchPoint1);
            touchPointVector.push_back(worldTouchPoint2);
            this->touchMap["pinch"]->setEnableTouch(true);
            this->touchMap["pinch"]->onBegan(touchPointVector);
        }
    } else if (BaseTouch::DOUBLE_TOUCH_COUNT == touches.size()) {
        this->touchMap["continuous"]->setEnableTouch(false);
        this->touchMap["swipe"]->setEnableTouch(false);
        this->touchMap["pinch"]->setEnableTouch(true);
        Touch* touch = touches.at(0);
        Vec2 worldTouchPoint1 = touch->getLocation();
        this->touchMap["pinch"]->setPreviousTouch(touch);
        touch = touches.at(1);
        Vec2 worldTouchPoint2 = touch->getLocation();
        std::vector<Point> touchPointVector;
        touchPointVector.push_back(worldTouchPoint1);
        touchPointVector.push_back(worldTouchPoint2);
        this->touchMap["pinch"]->onBegan(touchPointVector);
    }
}
void BattleLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event* event) {
    if (false == this->enableInput) {
        return;
    }
    Touch* touch1 = NULL;
    Touch* touch2 = NULL;
    bool doubleTouch = false;
    Touch* curentTouch = touches.at(0);
    if (BaseTouch::SINGLE_TOUCH_COUNT == touches.size()) {
        Touch* previousTouch = this->touchMap["pinch"]->getPreviousTouch();
        if (NULL != previousTouch && curentTouch->getID() != previousTouch->getID()) {
            touch1 = previousTouch;
            touch2 = touches.at(0);
            doubleTouch = true;
        }
    } else if (BaseTouch::DOUBLE_TOUCH_COUNT == touches.size()) {
        touch1 = touches.at(0);
        touch2 = touches.at(1);
        doubleTouch = true;
    }
    if (false == doubleTouch) {
        Touch* previousTouch = this->touchMap["continuous"]->getPreviousTouch();
        if (NULL == previousTouch || curentTouch->getID() != previousTouch->getID()) {
            return;
        }
        previousTouch = this->touchMap["swipe"]->getPreviousTouch();
        if (NULL == previousTouch || curentTouch->getID() != previousTouch->getID()) {
            return;
        }
        Vec2 worldTouchPoint = curentTouch->getLocation();
        Layer* unitLayer = (Layer*)this->getChildByTag(BaseLayer::NODE_LAYER_TAG);
        Vec2 nodeTouchPoint = unitLayer->convertToNodeSpace(worldTouchPoint);
        std::vector<Point> touchPointVector;
        touchPointVector.push_back(nodeTouchPoint);
        this->touchMap["continuous"]->onMove(touchPointVector);
        touchPointVector.clear();
        touchPointVector.push_back(worldTouchPoint);
        this->touchMap["swipe"]->onMove(touchPointVector);
    } else {
        Vec2 worldTouchPoint1 = touch1->getLocation();
        Vec2 worldTouchPoint2 = touch2->getLocation();
        std::vector<Point> touchPointVector;
        touchPointVector.push_back(worldTouchPoint1);
        touchPointVector.push_back(worldTouchPoint2);
        this->touchMap["pinch"]->onMove(touchPointVector);
    }
}
void BattleLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event* event) {
    if (false == this->enableInput) {
        return;
    }
    if (BaseTouch::SINGLE_TOUCH_COUNT == touches.size()) {
        Touch* touch = touches.at(0);
        Vec2 worldTouchPoint = touch->getLocation();
        Layer* unitLayer = (Layer*)this->getChildByTag(BaseLayer::NODE_LAYER_TAG);
        Vec2 nodeTouchPoint = unitLayer->convertToNodeSpace(worldTouchPoint);
        std::vector<Point> touchPointVector;
        touchPointVector.push_back(nodeTouchPoint);
        this->touchMap["continuous"]->onEnd(touchPointVector);
        touchPointVector.clear();
        touchPointVector.push_back(worldTouchPoint);
        this->touchMap["swipe"]->onEnd(touchPointVector);
    } else if (BaseTouch::DOUBLE_TOUCH_COUNT == touches.size()) {
        Touch* touch = touches.at(0);
        Vec2 worldTouchPoint1 = touch->getLocation();
        touch = touches.at(1);
        Vec2 worldTouchPoint2 = touch->getLocation();
        std::vector<Point> touchPointVector;
        touchPointVector.push_back(worldTouchPoint1);
        touchPointVector.push_back(worldTouchPoint2);
        this->touchMap["pinch"]->onEnd(touchPointVector);
    }
    std::map<std::string, BaseTouch*>::iterator it = this->touchMap.begin();
    while (it != this->touchMap.end()) {
        BaseTouch* touch = (BaseTouch*)it->second;
        touch->setPreviousTouch(NULL);
        it++;
    }
}
void BattleLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    if (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE) {
        CC_SAFE_DELETE(this->stateMachine);
        for (std::map<std::string, BaseTouch*>::iterator it = this->touchMap.begin(); it != this->touchMap.end(); it++) {
            CC_SAFE_DELETE(it->second);
        }
        BaseLayer::onKeyReleased(keyCode, event);
    }
    return;
}
void BattleLayer::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Battle_Scene_Battle_State || notifyMessage == NotifyMessage::Battle_Scene_Battle_Attack_State || notifyMessage == NotifyMessage::Battle_Scene_Win_State ||
        notifyMessage == NotifyMessage::Battle_Scene_Lose_State) {
        Parameter paramter;
        paramter.set<NotifyMessage>("message", notifyMessage);
        this->stateMachine->change("bgm", &paramter);
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Observation_State) {
        this->stateMachine->change("zoom");
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Shake_State) {
        this->stateMachine->change("shake");
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Complete_State) {
        this->stateMachine->change("transition");
    }
}
void BattleLayer::onExit() {
    CC_SAFE_DELETE(this->stateMachine);
    for (std::map<std::string, BaseTouch*>::iterator it = this->touchMap.begin(); it != this->touchMap.end(); it++) {
        CC_SAFE_DELETE(it->second);
    }
    BaseLayer::onExit();
}

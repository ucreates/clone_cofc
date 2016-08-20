//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include <cstddef>
#include "GeographicDepth.h"
#include "BattleUIBehaviour.h"
#include "BehaviourIdGenerator.h"
#include "UnitBehaviourType.h"
#include "BattleUIBehaviour.h"
#include "UIProperty.h"
#include "Notifier.h"
#include "UIAsset.h"
#include "TextureAsset.h"
#include "Screen.h"
#include "Parameter.h"
#include "ServiceGateway.h"
using namespace cocos2d;
BattleUIBehaviour::BattleUIBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("battle", new UIAsset("csb/scene/battle/layer/battle"));
    this->asset->add("result", new UIAsset("csb/scene/battle/layer/result"));
    this->property = new UIProperty("battle", id);
    this->stateMachine = new FiniteStateMachine<BattleUIBehaviour>(this);
    this->stateMachine->add("battle", new BattleUIBattleState());
    this->stateMachine->add("result", new BattleUIResultState());
    this->stateMachine->add("count", new BattleUICountState());
    this->stateMachine->add("timer", new BattleUITimerState());
    this->stateMachine->add("resource", new BattleUIResourceState());
    this->stateMachine->stop();
    Notifier::getInstance()->add(this, this->property);
}
BattleUIBehaviour::~BattleUIBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void BattleUIBehaviour::onCreate(Layer* layer) {
    this->onCreate(layer, GeographicDepth::UI_DEPTH);
    return;
}
void BattleUIBehaviour::onCreate(Layer* layer, int depth) {
    this->layer = layer;
    UIAsset* asset = (UIAsset*)this->getAsset("battle");
    asset->play();
    asset->addLayer(layer, depth);
    asset->findByName<ui::Button*>("endBattleButton")->addTouchEventListener(CC_CALLBACK_2(BattleUIBehaviour::onEndBattleButton, this));
    asset->findByName<ui::Button*>("archerSelectButton")->addTouchEventListener(CC_CALLBACK_2(BattleUIBehaviour::onPushUnitSelectButton, this));
    asset->findByName<ui::Button*>("barbarianSelectButton")->addTouchEventListener(CC_CALLBACK_2(BattleUIBehaviour::onPushUnitSelectButton, this));
    asset->findByName<ui::Button*>("giantSelectButton")->addTouchEventListener(CC_CALLBACK_2(BattleUIBehaviour::onPushUnitSelectButton, this));
    asset->findByName<ui::Button*>("goblinSelectButton")->addTouchEventListener(CC_CALLBACK_2(BattleUIBehaviour::onPushUnitSelectButton, this));
    asset->findByName<ui::Button*>("wallBreakerSelectButton")->addTouchEventListener(CC_CALLBACK_2(BattleUIBehaviour::onPushUnitSelectButton, this));
    asset = (UIAsset*)this->getAsset("result");
    asset->findByName<ui::Button*>("returnHomeButton")->addTouchEventListener(CC_CALLBACK_2(BattleUIBehaviour::onEndBattleButton, this));
    this->stateMachine->change("battle");
    this->stateMachine->stop();
    return;
}
void BattleUIBehaviour::onUpdate(float time) {
    this->stateMachine->update(time);
    return;
}
void BattleUIBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Battle_Scene_Win_State || notifyMessage == NotifyMessage::Battle_Scene_Lose_State) {
        this->stateMachine->change("result");
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Battle_State) {
        this->stateMachine->play();
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Score_Update_State) {
        this->stateMachine->change("count");
        this->stateMachine->play();
    } else if (notifyMessage == NotifyMessage::Battle_Scene_OverAll_Level1_State) {
        UIAsset* asset = (UIAsset*)this->getAsset("battle");
        asset->play("level1", NULL);
        this->stateMachine->play();
    } else if (notifyMessage == NotifyMessage::Battle_Scene_OverAll_Level2_State) {
        UIAsset* asset = (UIAsset*)this->getAsset("battle");
        asset->play("level2", NULL);
        this->stateMachine->play();
    } else if (notifyMessage == NotifyMessage::Battle_Scene_OverAll_Level3_State) {
        std::function<void()> endFrameCallback = [this]() { Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_Win_State); };
        UIAsset* asset = (UIAsset*)this->getAsset("battle");
        asset->play("level3", endFrameCallback);
        this->stateMachine->play();
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Build_State) {
        this->stateMachine->change("count");
        this->stateMachine->play();
    }
    return;
}
void BattleUIBehaviour::onEndBattleButton(Ref* pSender, ui::Widget::TouchEventType type) {
    if (type != ui::Widget::TouchEventType::BEGAN) {
        return;
    }
    Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_Complete_State);
}
void BattleUIBehaviour::onPushUnitSelectButton(Ref* pSender, ui::Widget::TouchEventType type) {
    std::string buttonList[5] = {"archerSelectButton", "barbarianSelectButton", "giantSelectButton", "goblinSelectButton", "wallBreakerSelectButton"};
    ui::Button* button = dynamic_cast<ui::Button*>(pSender);
    for (int i = 0; i < 5; i++) {
        std::string buttonName = buttonList[i];
        if (buttonName == button->getName()) {
            this->setActiveButtonTexture(buttonName);
            this->updateActiveUnit(buttonName);
        } else {
            this->setNormalButtonTexture(buttonName);
        }
    }
}
void BattleUIBehaviour::setNormalButtonTexture(std::string buttonName) {
    UIAsset* asset = (UIAsset*)this->getAsset("battle");
    ui::Button* button = asset->findByName<ui::Button*>(buttonName);
    std::string textureName = "";
    if ("archerSelectButton" == buttonName) {
        textureName = "img/battle/archer_select_button_normal.png";
    } else if ("barbarianSelectButton" == buttonName) {
        textureName = "img/battle/barbarian_select_button_normal.png";
    } else if ("giantSelectButton" == buttonName) {
        textureName = "img/battle/giant_select_button_normal.png";
    } else if ("goblinSelectButton" == buttonName) {
        textureName = "img/battle/goblin_select_button_normal.png";
    } else if ("wallBreakerSelectButton" == buttonName) {
        textureName = "img/battle/wallbreaker_select_button_normal.png";
    }
    button->loadTextureNormal(textureName, ui::Widget::TextureResType::LOCAL);
}
void BattleUIBehaviour::setActiveButtonTexture(std::string buttonName) {
    UIAsset* asset = (UIAsset*)this->getAsset("battle");
    ui::Button* button = asset->findByName<ui::Button*>(buttonName);
    std::string textureName = "";
    if ("archerSelectButton" == buttonName) {
        textureName = "img/battle/archer_select_button_active.png";
    } else if ("barbarianSelectButton" == buttonName) {
        textureName = "img/battle/barbarian_select_button_active.png";
    } else if ("giantSelectButton" == buttonName) {
        textureName = "img/battle/giant_select_button_active.png";
    } else if ("goblinSelectButton" == buttonName) {
        textureName = "img/battle/goblin_select_button_active.png";
    } else if ("wallBreakerSelectButton" == buttonName) {
        textureName = "img/battle/wallbreaker_select_button_active.png";
    }
    button->loadTextureNormal(textureName, ui::Widget::TextureResType::LOCAL);
}
void BattleUIBehaviour::updateActiveUnit(std::string buttonName) {
    int unitId = 0;
    if ("archerSelectButton" == buttonName) {
        unitId = UnitBehaviourType::Archer;
    } else if ("barbarianSelectButton" == buttonName) {
        unitId = UnitBehaviourType::Barbarian;
    } else if ("giantSelectButton" == buttonName) {
        unitId = UnitBehaviourType::Giant;
    } else if ("goblinSelectButton" == buttonName) {
        unitId = UnitBehaviourType::Goblin;
    } else if ("wallBreakerSelectButton" == buttonName) {
        unitId = UnitBehaviourType::WallBreaker;
    }
    Parameter parameter;
    parameter.set<int>("unitId", unitId);
    Response res = ServiceGateway::getInstance()->request("service://resource/select")->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    res.clear();
}

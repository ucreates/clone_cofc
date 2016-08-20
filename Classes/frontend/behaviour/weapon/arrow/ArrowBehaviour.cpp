//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "ArrowBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "WeaponProperty.h"
// asset
#include "TextureAsset.h"
// notify
#include "Notifier.h"
using namespace cocos2d;
ArrowBehaviour::ArrowBehaviour(GeographicNode* start, GeographicNode* goal, int ownerId, float paddingHeight, bool isEnemy, bool debug) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new TextureAsset("img/weapon/arrow/arrow1.png"));
    this->paddingHeight = paddingHeight;
    this->property = new WeaponProperty("arrow", id, ownerId, isEnemy);
    this->stateMachine = new FiniteStateMachine<ArrowBehaviour>(this);
    this->stateMachine->add("active", new ArrowActiveBezier3DState());
    this->stateMachine->add("destroy", new ArrowDestroyState());
    Notifier::getInstance()->add(this, this->property);
}
ArrowBehaviour::~ArrowBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void ArrowBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;
    float x = position.x;
    float y = position.y + this->paddingHeight;
    BaseRenderAsset* texture = (BaseRenderAsset*)this->getAsset("anime");
    texture->transform(x, y);
    texture->transform(position.zorder);
    texture->hide();
    texture->addLayer(layer, position.zorder);
    this->stateMachine->change("active");
    this->stateMachine->play();
    this->property->setStatus(BehaviourStatus::ACTIVE);
}
void ArrowBehaviour::onUpdate(float delta) { this->stateMachine->update(delta); }
void ArrowBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Behaviour_Weapon_Destroy) {
        this->stateMachine->change("destroy", true);
    }
    if (notifyMessage == NotifyMessage::Behaviour_Weapon_Active) {
        this->stateMachine->change("active");
    }
    this->stateMachine->play();
}
void ArrowBehaviour::setProperty(GeographicNode* start, GeographicNode* goal, float paddingHeight, bool isEnemy, bool debug) {
    this->start = start;
    this->goal = goal;
    this->paddingHeight = paddingHeight;
    this->debug = debug;
}

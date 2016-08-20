//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "MortarBulletBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "WeaponProperty.h"
// asset
#include "TextureAsset.h"
// notify
#include "Notifier.h"
using namespace cocos2d;
MortarBulletBehaviour::MortarBulletBehaviour(GeographicNode* start, GeographicNode* goal, int ownerId, bool debug) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new TextureAsset("img/weapon/mortar_bullet/mortar_bullet.png"));
    this->property = new WeaponProperty("mortarBullet", id, ownerId, true);
    this->stateMachine = new FiniteStateMachine<MortarBulletBehaviour>(this);
    this->stateMachine->add("active", new MortarBulletActiveState());
    this->stateMachine->add("destroy", new MortarBulletDestroyState());
    this->start = start;
    this->goal = goal;
    this->debug = debug;
    Notifier::getInstance()->add(this, this->property);
}
MortarBulletBehaviour::~MortarBulletBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void MortarBulletBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;
    BaseRenderAsset* texture = (BaseRenderAsset*)this->getAsset("anime");
    texture->transform(position);
    texture->addLayer(layer, position.zorder);
    this->stateMachine->change("active");
    this->stateMachine->play();
    this->property->setStatus(BehaviourStatus::ACTIVE);
}
void MortarBulletBehaviour::onUpdate(float delta) { this->stateMachine->update(delta); }
void MortarBulletBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Behaviour_Weapon_Destroy) {
        this->stateMachine->change("destroy", true);
    }
    if (notifyMessage == NotifyMessage::Behaviour_Weapon_Active) {
        this->stateMachine->change("active");
    }
    this->stateMachine->play();
}
void MortarBulletBehaviour::setProperty(GeographicNode* start, GeographicNode* goal, bool debug) {
    this->start = start;
    this->goal = goal;
    this->debug = debug;
}

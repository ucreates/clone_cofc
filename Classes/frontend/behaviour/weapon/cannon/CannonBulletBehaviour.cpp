//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "CannonBulletBehaviour.h"

// peroperty
#include "WeaponProperty.h"
#include "BehaviourIdGenerator.h"

#include "Notifier.h"

// asset
#include "TextureAsset.h"

// effect
#include "CannonFireEffectBehaviour.h"
#include "BehaviourMapper.h"

using namespace cocos2d;

CannonBulletBehaviour::CannonBulletBehaviour(GeographicNode* node, int ownerId, float degree, bool debug) {
    int id = BehaviourIdGenerator::getInstance()->getId();

    this->asset->add("anime", new TextureAsset("img/weapon/cannon/cnannon_bullet.png"));
    this->property = new WeaponProperty("cannonBullet", id, ownerId, true);
    this->stateMachine = new FiniteStateMachine<CannonBulletBehaviour>(this);
    this->stateMachine->add("active", new CannonBulletActiveState());
    this->stateMachine->add("destroy", new CannonBulletDestroyState());

    this->start = node;
    this->degree = degree;
    this->debug = debug;
    Notifier::getInstance()->add(this, this->property);
}

CannonBulletBehaviour::~CannonBulletBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }

void CannonBulletBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;

    float radian = CC_DEGREES_TO_RADIANS(this->degree);
    float sin = sinf(radian);
    float cos = cosf(radian);
    position.add(Vec2(35.0f * cos, 35.0f * sin));

    BaseRenderAsset* texture = (BaseRenderAsset*)this->getAsset("anime");
    texture->transform(position);
    texture->addLayer(layer, position.zorder);

    Position epos = Position(Vec2(this->start->position.x + 25.0f * cos, this->start->position.y + 45.0f * sin), position.zorder);
    CannonFireEffectBehaviour effect;
    effect.onCreate(this->getLayer(), epos);

    Parameter parameter;
    parameter.set<float>("degree", this->degree);
    this->stateMachine->change("active", &parameter);
    this->stateMachine->play();

    this->property->setStatus(BehaviourStatus::ACTIVE);
}

void CannonBulletBehaviour::onUpdate(float delta) { this->stateMachine->update(delta); }

void CannonBulletBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Behaviour_Weapon_Destroy) {
        this->stateMachine->change("destroy", true);
    } else if (notifyMessage == NotifyMessage::Behaviour_Weapon_Active) {
        this->stateMachine->change("active");
    }

    this->stateMachine->play();
}

void CannonBulletBehaviour::setProperty(GeographicNode* node, float degree, bool debug) {
    this->start = node;
    this->degree = degree;
    this->debug = debug;
}

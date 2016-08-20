//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "TowerArcherBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "UnitProperty.h"
// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"
#include "SoundAssetCollection.h"
// notify
#include "Notifier.h"
using namespace cocos2d;
TowerArcherBehaviour::TowerArcherBehaviour() {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/unit/archer", id));
    this->asset->add("se1", SoundAssetCollection::getInstance()->getSEAsset("sound/se/archer_tower_pick_01.mp3"));
    this->property = new UnitProperty("TowerArcher", id);
    this->stateMachine = new FiniteStateMachine<TowerArcherBehaviour>(this);
    this->stateMachine->add("search", new TowerArcherSearchState());
    this->stateMachine->add("attack", new TowerArcherAttackState(id));
    this->stateMachine->add("win", new TowerArcherWinState());
    this->stateMachine->add("lose", new TowerArcherLoseState());
    this->stateMachine->stop();
    Notifier::getInstance()->add(this, this->property);
}
TowerArcherBehaviour::~TowerArcherBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void TowerArcherBehaviour::onCreate(Layer* layer, Position position) {
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->transform(position);
    anime->transform(Size(0.75f, 0.75f));
    anime->addLayer(layer, position.zorder);
    this->shadow->onCreate(layer, position, Size(1.0f, 1.0f));
    this->stateMachine->change("search");
    this->stateMachine->play();
}
void TowerArcherBehaviour::onUpdate(float delta) { this->stateMachine->update(delta); }
void TowerArcherBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (notifyMessage == NotifyMessage::Behaviour_Barrier_Tower_Archer_Search) {
        this->stateMachine->change("search");
    } else if (notifyMessage == NotifyMessage::Behaviour_Barrier_Tower_Archer_Attack) {
        this->stateMachine->change("attack", parameter);
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Win_State) {
        this->stateMachine->change("win");
    } else if (notifyMessage == NotifyMessage::Battle_Scene_Lose_State) {
        this->stateMachine->change("lose");
    }
    this->stateMachine->play();
}
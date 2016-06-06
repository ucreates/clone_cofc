//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// cocos2d
#include "cocos2d.h"

// behaviour
#include "BehaviourCollection.h"
#include "BehaviourIdGenerator.h"
#include "BehaviourMapper.h"

// command
#include "CommandGateway.h"

// geopgraphy
#include "GeographicGateway.h"

// layer
#include "BattleLayer.h"
#include "LogoLayer.h"
#include "LoadingLayer.h"

// notifier
#include "Notifier.h"

// scene
#include "SceneFactory.h"

// service
#include "CommunicationGateway.h"
#include "DataBase.h"
#include "ServiceGateway.h"

// sound
#include "SoundAssetCollection.h"

// state
#include "BaseTransitionState.h"

using namespace cocos2d;

template <typename T>
BaseTransitionState<T>::BaseTransitionState() {}

template <typename T>
BaseTransitionState<T>::~BaseTransitionState() {}

template <typename T>
void BaseTransitionState<T>::transition(T* owner, int sceneId) {
    owner->getStateMachine()->stop();
    owner->unscheduleUpdate();

    BehaviourIdGenerator::destroy();
    BehaviourCollection::destroy();
    BehaviourMapper::destroy();
    GeographicGateway::destroy();
    Notifier::destroy();
    CommandGateway::destroy();
    SoundAssetCollection::getInstance()->stop();
    Scene* scene = SceneFactory::factoryMethod(sceneId);
    Director::getInstance()->replaceScene(scene);
    return;
}

template class BaseTransitionState<LogoLayer>;
template class BaseTransitionState<LoadingLayer>;
template class BaseTransitionState<BattleLayer>;

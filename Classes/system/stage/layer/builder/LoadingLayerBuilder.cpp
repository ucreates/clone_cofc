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
#include "BehaviourCollection.h"
// builder
#include "LoadingLayerBuilder.h"
// command
#include "BaseCommand.h"
#include "CommandGateway.h"
// state
#include "LoadingLayerShowState.h"
#include "LoadingLayerTransitionState.h"
// geography
#include "GeographicDepth.h"
// notifier
#include "Notifier.h"
#include "NotifyMessage.h"
LoadingLayerBuilder::LoadingLayerBuilder() {}
LoadingLayerBuilder::~LoadingLayerBuilder() {}
void LoadingLayerBuilder::build() {
    BaseLayerBuilder::build();
    LoadingLayer* loadingLayer = (LoadingLayer*)this->rootLayer;
    loadingLayer->stateMachine = new FiniteStateMachine<LoadingLayer>(loadingLayer);
    loadingLayer->stateMachine->add("show", new LoadingLayerShowState());
    loadingLayer->stateMachine->add("transition", new LoadingLayerTransitionState());
    loadingLayer->stateMachine->stop();
    Notifier::getInstance()->add(loadingLayer, loadingLayer->property);
    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector("ui");
    for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        std::string behaviourType = behaviour->getProperty()->getType();
        BaseCommand* command = CommandGateway::getInstance()->getCommand(behaviourType);
        command->initialize(behaviour, this->rootLayer, GeographicDepth::UI_DEPTH);
    }
    Notifier::getInstance()->notify(NotifyMessage::Loading_Scene_Show_State);
    loadingLayer->scheduleUpdate();
}
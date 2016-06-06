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
#include "LogoLayerBuilder.h"

// command
#include "BaseCommand.h"
#include "CommandGateway.h"

// geography
#include "GeographicDepth.h"

// notify
#include "Notifier.h"

// service
#include "ServiceGateway.h"

// state
#include "LogoLayerShowState.h"
#include "LogoLayerTransitionState.h"

LogoLayerBuilder::LogoLayerBuilder() {}

LogoLayerBuilder::~LogoLayerBuilder() {}

void LogoLayerBuilder::build() {
    BaseLayerBuilder::build();

    Response res = ServiceGateway::getInstance()->request("service://logo/clear")->update();
    res.clear();

    LogoLayer* logoLayer = (LogoLayer*)this->rootLayer;
    logoLayer->stateMachine = new FiniteStateMachine<LogoLayer>(logoLayer);
    logoLayer->stateMachine->add("show", new LogoLayerShowState());
    logoLayer->stateMachine->add("transition", new LogoLayerTransitionState());
    logoLayer->stateMachine->stop();

    Notifier::getInstance()->add(logoLayer, logoLayer->property);

    BehaviourCollection* collection = BehaviourCollection::getInstance();
    std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector("ui");
    for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        std::string behaviourType = behaviour->getProperty()->getType();
        BaseCommand* command = CommandGateway::getInstance()->getCommand(behaviourType);
        command->initialize(behaviour, this->rootLayer, GeographicDepth::UI_DEPTH);
    }

    Notifier::getInstance()->notify(NotifyMessage::Logo_Scene_Show_State);
    logoLayer->scheduleUpdate();
}
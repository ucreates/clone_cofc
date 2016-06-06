//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "CommandGateway.h"
#include "UICommand.h"
#include "OrnamentCommand.h"
#include "WeaponCommand.h"
#include "UnitCommand.h"
#include "BackGroundCommand.h"
#include "EffectCommand.h"

CommandGateway* CommandGateway::instance = new CommandGateway();

CommandGateway::CommandGateway() {
    this->commandCacheMap = new std::map<std::string, BaseCommand*>();
    this->commandCacheMap->insert(std::map<std::string, BaseCommand*>::value_type("ui", new UICommand()));
    this->commandCacheMap->insert(std::map<std::string, BaseCommand*>::value_type("effect", new EffectCommand()));
    this->commandCacheMap->insert(std::map<std::string, BaseCommand*>::value_type("ornament", new OrnamentCommand()));
    this->commandCacheMap->insert(std::map<std::string, BaseCommand*>::value_type("unit", new UnitCommand()));
    this->commandCacheMap->insert(std::map<std::string, BaseCommand*>::value_type("weapon", new WeaponCommand()));
    this->commandCacheMap->insert(std::map<std::string, BaseCommand*>::value_type("background", new BackGroundCommand()));
}

CommandGateway::~CommandGateway() {
    for (std::map<std::string, BaseCommand*>::iterator it = this->commandCacheMap->begin(); it != this->commandCacheMap->end(); ++it) {
        CC_SAFE_DELETE(it->second);
    }

    CC_SAFE_DELETE(this->commandCacheMap);
}

CommandGateway* CommandGateway::getInstance() {
    if (NULL == CommandGateway::instance) {
        CommandGateway::instance = new CommandGateway();
    }
    return CommandGateway::instance;
}

void CommandGateway::destroy() { CC_SAFE_DELETE(CommandGateway::instance); }

BaseCommand* CommandGateway::getCommand(std::string commandName) {
    if (0 == this->commandCacheMap->count(commandName)) {
        return NULL;
    }
    return this->commandCacheMap->at(commandName);
}

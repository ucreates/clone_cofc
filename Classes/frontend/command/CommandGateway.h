//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef CommandGateway_h
#define CommandGateway_h
#include <map>
#include "BaseCommand.h"
class CommandGateway {
   public:
    ~CommandGateway();
    static CommandGateway* getInstance();
    static void destroy();
    BaseCommand* getCommand(std::string commandName);
   private:
    std::map<std::string, BaseCommand*>* commandCacheMap;
    static CommandGateway* instance;
    CommandGateway();
};
#endif

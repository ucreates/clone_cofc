//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ServiceGateway_h
#define ServiceGateway_h

// stl
#include <map>

// service
#include "BaseService.h"
#include "BaseStrategy.h"

class ServiceGateway {
   public:
    ~ServiceGateway();
    static ServiceGateway* getInstance();
    BaseStrategy* request(std::string serviceName);
    bool add(std::string serviceName, BaseService* service);
    void clear();
    static void destroy();

   private:
    static ServiceGateway* instance;
    std::map<std::string, BaseService*> serviceMap;
    ServiceGateway();
};

#endif

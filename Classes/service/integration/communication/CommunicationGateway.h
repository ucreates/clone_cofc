//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef CommunicationGateway_h
#define CommunicationGateway_h

// stl
#include <map>

// cocos2d
#include "network/HttpClient.h"
#include "cocos2d.h"

// service
#include "BaseCallback.h"

class CommunicationGateway {
   public:
    ~CommunicationGateway();
    static CommunicationGateway* getInstance();
    void request(std::string url, cocos2d::network::HttpRequest::Type methodType = cocos2d::network::HttpRequest::Type::GET);
    void response(cocos2d::network::HttpClient* sender, cocos2d::network::HttpResponse* response);
    void setCallback(std::string callbackName);
    static void destroy();

   private:
    static const int TIME_OUT = 300;
    BaseCallback* callback;
    std::map<std::string, BaseCallback*> callbackList;
    static CommunicationGateway* instance;
    CommunicationGateway();
};

#endif
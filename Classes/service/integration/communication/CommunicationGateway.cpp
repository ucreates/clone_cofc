//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// service
#include "AssetXmlCallback.h"
#include "AssetCallback.h"
#include "CommunicationGateway.h"

using namespace cocos2d::network;

CommunicationGateway* CommunicationGateway::instance = NULL;

CommunicationGateway::CommunicationGateway() {
    this->callback = NULL;
    this->callbackList.insert(std::map<std::string, BaseCallback*>::value_type("assetXml", new AssetXmlCallback()));
    this->callbackList.insert(std::map<std::string, BaseCallback*>::value_type("asset", new AssetCallback()));
}

CommunicationGateway::~CommunicationGateway() {
    for (std::map<std::string, BaseCallback*>::iterator it = this->callbackList.begin(); it != this->callbackList.end(); it++) {
        CC_SAFE_DELETE(it->second);
    }
    this->callback = NULL;
}

CommunicationGateway* CommunicationGateway::getInstance() {
    if (NULL == CommunicationGateway::instance) {
        CommunicationGateway::instance = new CommunicationGateway();
    }
    return CommunicationGateway::instance;
}

void CommunicationGateway::request(std::string url, HttpRequest::Type methodType) {
    HttpRequest* request = new HttpRequest();
    request->setUrl(url.c_str());
    request->setRequestType(methodType);
    request->setResponseCallback(CC_CALLBACK_2(CommunicationGateway::response, this));
    HttpClient* client = HttpClient::getInstance();
    client->setTimeoutForConnect(CommunicationGateway::TIME_OUT);
    client->send(request);
    request->release();
}

void CommunicationGateway::response(HttpClient* sender, HttpResponse* response) {
    if (response->isSucceed()) {
        if (NULL != this->callback) {
            this->callback->onSuccess(sender, response);
        }
    } else {
        if (NULL != this->callback) {
            this->callback->onFaild(sender, response);
        }
    }

    return;
}

void CommunicationGateway::destroy() { CC_SAFE_DELETE(CommunicationGateway::instance); }

void CommunicationGateway::setCallback(std::string callbackName) { this->callback = this->callbackList[callbackName]; }

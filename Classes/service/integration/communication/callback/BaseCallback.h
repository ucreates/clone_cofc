//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseCallback_h
#define BaseCallback_h
// cocos2d
#include "cocos2d.h"
#include "network/HttpClient.h"
class BaseCallback {
   public:
    virtual void onSuccess(cocos2d::network::HttpClient* sender, cocos2d::network::HttpResponse* response);
    virtual void onFaild(cocos2d::network::HttpClient* sender, cocos2d::network::HttpResponse* response);
};
#endif

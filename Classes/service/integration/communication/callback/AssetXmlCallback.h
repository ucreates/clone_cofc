//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef AssetXmlCallback_h
#define AssetXmlCallback_h
// cocos2d
#include "cocos2d.h"
#include "network/HttpClient.h"
// service
#include "BaseCallback.h"
class AssetXmlCallback : public BaseCallback {
   public:
    void onSuccess(cocos2d::network::HttpClient* sender, cocos2d::network::HttpResponse* response) override;
    void onFaild(cocos2d::network::HttpClient* sender, cocos2d::network::HttpResponse* response) override;
};
#endif

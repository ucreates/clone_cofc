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
#include "AssetCallback.h"
#include "AssetBizLogic.h"

using namespace std;
using namespace cocos2d::network;

void AssetCallback::onSuccess(HttpClient* sender, HttpResponse* response) {
    if (response->isSucceed()) {
        std::vector<char>* dataVector = response->getResponseData();
        string requestUrl = response->getHttpRequest()->getUrl();
        AssetBizLogic asset;
        asset.saveAsset(requestUrl, dataVector);
    }
    return;
}

void AssetCallback::onFaild(HttpClient* sender, HttpResponse* response) { CCLOGERROR("AssetCallback::onFaild"); }

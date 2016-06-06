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
#include "BaseCallback.h"

using namespace cocos2d;
using namespace cocos2d::network;

void BaseCallback::onSuccess(HttpClient* sender, HttpResponse* response) {
    CCLOGINFO("BaseCallback::onSuccess");
    return;
}

void BaseCallback::onFaild(HttpClient* sender, HttpResponse* response) {
    CCLOGERROR("BaseCallback::onFaild");
    return;
}

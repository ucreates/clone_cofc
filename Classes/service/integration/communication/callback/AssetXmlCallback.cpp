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
#include "AssetXmlAssembler.h"
#include "AssetBizLogic.h"
#include "CommunicationGateway.h"
#include "Parameter.h"
#include "ServiceGateway.h"
#include "TAssetTable.h"
using namespace cocos2d;
using namespace cocos2d::network;
void AssetXmlCallback::onSuccess(HttpClient* sender, HttpResponse* response) {
    if (response->isSucceed()) {
        std::vector<char>* dataVector = response->getResponseData();
        std::string xml(dataVector->begin(), dataVector->end());
        AssetXmlAssembler assembler(xml);
        std::vector<TAssetTable> ret = assembler.writeToVector();
        Parameter parameter;
        parameter.set<std::vector<TAssetTable>>("requestAssetVector", ret);
        Response res = ServiceGateway::getInstance()->request("service://loading/download")->update(&parameter);
        if (ServiceStatus::SUCCESS != res.getStatus()) {
            CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
        }
        res.clear();
    }
    return;
}
void AssetXmlCallback::onFaild(HttpClient* sender, HttpResponse* response) { CCLOGERROR("AssetXmlCallback::onFaild"); }

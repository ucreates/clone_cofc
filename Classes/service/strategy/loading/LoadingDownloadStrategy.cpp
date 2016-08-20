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
#include "LoadingDownloadStrategy.h"
#include "AssetBizLogic.h"
#include "TAssetTable.h"
LoadingDownloadStrategy::LoadingDownloadStrategy() {}
LoadingDownloadStrategy::~LoadingDownloadStrategy() {}
Response LoadingDownloadStrategy::get(Parameter* parameter) {
    Response res;
    AssetBizLogic assetBizLogic;
    float percentage = assetBizLogic.getDownLoadPercent();
    bool emitDownload = assetBizLogic.getEmitDownloadAsset();
    if (false == emitDownload) {
        percentage = 100.0f;
    }
    if (percentage < 0.0f) {
        res.setStatus(ServiceStatus::FAILD);
    }
    std::string message = assetBizLogic.getDownloadMessage();
    res.set<float>("downloadPercentage", percentage);
    res.set<bool>("emitDownload", emitDownload);
    res.set<std::string>("message", message);
    return res;
}
Response LoadingDownloadStrategy::request(Parameter* parameter) {
    AssetBizLogic assetBizLogic;
    bool emitDownload = parameter->get<bool>("emitDownload");
    assetBizLogic.setEmitDownloadAsset(emitDownload);
    if (false != emitDownload) {
        assetBizLogic.request("assetXml");
    }
    Response res;
    return res;
}
Response LoadingDownloadStrategy::update(Parameter* parameter) {
    std::vector<TAssetTable> requestAssetVector = parameter->get<std::vector<TAssetTable>>("requestAssetVector");
    int totalAssetCount = (int)requestAssetVector.size();
    AssetBizLogic assetBizLogic;
    assetBizLogic.updateDownloadAssetCount(totalAssetCount);
    for (std::vector<TAssetTable>::iterator it = requestAssetVector.begin(); it != requestAssetVector.end(); it++) {
        assetBizLogic.request("asset", AssetBizLogic::ASSET_ROOT_URI + it->path);
    }
    Response res;
    return res;
}
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// stl
#include <iostream>
#include <fstream>
// debug
#include "Macro.h"
// service
#include "AssetBizLogic.h"
#include "AssetXmlCallback.h"
#include "CommunicationGateway.h"
#include "DataBase.h"
#include "Dao.h"
#include "LoadingMessageXmlAssembler.h"
#include "TDownLoadTable.h"
// utility
#include "StringUtility.h"
// io
#include "BinaryStream.h"
#include "Directory.h"
// math
#include "Random.h"
using namespace cocos2d;
const std::string AssetBizLogic::ASSET_DMAIN = "http://xxx.xxx.xxx.xxx/";
const std::string AssetBizLogic::ASSET_ROOT_URI = "http://xxx.xxx.xxx.xxx/contents/clone_cofc_asset/";
const std::string AssetBizLogic::ASSET_LIST_URI = "http://xxx.xxx.xxx.xxx/contents/clone_cofc_asset/index.xml";
AssetBizLogic::AssetBizLogic() {
    DataBase* db = DataBase::getInstance();
    Dao<TDownLoadTable>* dao = db->findBy<TDownLoadTable>();
    if (0 == dao->count()) {
        dao->save();
    }
    this->stream = new BinaryStream();
}
AssetBizLogic::~AssetBizLogic() { CC_SAFE_DELETE(this->stream); }
void AssetBizLogic::request(std::string requestName) { this->request(requestName, AssetBizLogic::ASSET_LIST_URI); }
void AssetBizLogic::request(std::string requestName, std::string requestUrl) {
    DataBase* db = DataBase::getInstance();
    Dao<TDownLoadTable>* dao = db->findBy<TDownLoadTable>();
    TDownLoadTable record = dao->findFirst();
    if (false != record.isAssetCache) {
        return;
    }
    CommunicationGateway* client = CommunicationGateway::getInstance();
    client->setCallback(requestName);
    client->request(requestUrl);
}
void AssetBizLogic::updateDownloadAssetCount(int totalDownloadAssetCount) {
    DataBase* db = DataBase::getInstance();
    Dao<TDownLoadTable>* dao = db->findBy<TDownLoadTable>();
    TDownLoadTable record = dao->findFirst();
    record.total = totalDownloadAssetCount;
    dao->update(record);
}
bool AssetBizLogic::saveAsset(std::string requestUrl, std::vector<char>* dataVector) {
    std::string rootPath = FileUtils::getInstance()->getWritablePath();
    std::string relativePath = StringUtility::replace(requestUrl, AssetBizLogic::ASSET_DMAIN, "");
    std::string filePath = rootPath + relativePath;
    std::string dirName = Directory::getDirectoryName(filePath);
    bool ret = FileUtils::getInstance()->createDirectory(dirName);
    if (false == ret) {
        CCLOGERROR("can't create directory::%s", dirName.c_str());
        return false;
    }
    FileUtils::getInstance()->addSearchPath(dirName);
    this->stream->write(filePath, dataVector);
    DataBase* db = DataBase::getInstance();
    Dao<TDownLoadTable>* dao = db->findBy<TDownLoadTable>();
    TDownLoadTable record = dao->findFirst();
    record.current++;
    if (record.current == record.total) {
        record.isAssetCache = true;
    }
    dao->update(record);
    return true;
}
bool AssetBizLogic::setEmitDownloadAsset(bool emit) {
    DataBase* db = DataBase::getInstance();
    Dao<TDownLoadTable>* dao = db->findBy<TDownLoadTable>();
    TDownLoadTable record = dao->findFirst();
    if (false == record.isAssetCache) {
        record.emitDownLoad = emit;
    } else {
        record.emitDownLoad = true;
    }
    return dao->update(record);
}
bool AssetBizLogic::getEmitDownloadAsset() {
    DataBase* db = DataBase::getInstance();
    Dao<TDownLoadTable>* dao = db->findBy<TDownLoadTable>();
    TDownLoadTable record = dao->findFirst();
    return record.emitDownLoad;
}
float AssetBizLogic::getDownLoadPercent() {
    DataBase* db = DataBase::getInstance();
    Dao<TDownLoadTable>* dao = db->findBy<TDownLoadTable>();
    TDownLoadTable record = dao->findFirst();
    if (false != record.isAssetCache || (0 < record.current && 0 < record.total && record.current == record.total)) {
        return 100.0f;
    }
    float percentage = (float)record.current / (float)record.total * 100.0f;
    return percentage;
}
std::string AssetBizLogic::getDownloadMessage() {
    LoadingMessageXmlAssembler assembler("config/loading/message.xml");
    std::vector<std::string> ret = assembler.writeToVector();
    int index = Random::create(ret.size(), true);
    return ret.at(index);
}
void AssetBizLogic::clear() {
    DataBase* db = DataBase::getInstance();
    Dao<TDownLoadTable>* dao = db->findBy<TDownLoadTable>();
    TDownLoadTable record = dao->findFirst();
    record.current = 0;
    record.total = 0;
    record.emitDownLoad = false;
    dao->update(record);
    return;
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef AssetBizLogic_h
#define AssetBizLogic_h

#include <string>
#include <vector>
#include "BaseBizLogic.h"
#include "BaseStream.h"

class AssetBizLogic : public BaseBizLogic {
   public:
    static const std::string ASSET_DMAIN;
    static const std::string ASSET_ROOT_URI;
    static const std::string ASSET_LIST_URI;
    AssetBizLogic();
    ~AssetBizLogic();
    void request(std::string requestName);
    void request(std::string requestName, std::string requestUrl);
    void updateDownloadAssetCount(int totalDownloadAssetCount);
    float getDownLoadPercent();
    bool saveAsset(std::string requestUrl, std::vector<char>* dataVector);
    bool setEmitDownloadAsset(bool emit);
    bool getEmitDownloadAsset();
    std::string getDownloadMessage();
    void clear() override;

   private:
    BaseStream* stream;
};

#endif

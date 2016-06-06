//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef AssetCollection_h
#define AssetCollection_h

#include <map>
#include <string>

// asset
#include "BaseAsset.h"

class BaseAsset;

class AssetCollection {
   public:
    AssetCollection();
    ~AssetCollection();
    BaseAsset* find(std::string assetName);
    void add(std::string assetName, BaseAsset* asset);
    void erase(std::string assetName);
    std::map<std::string, BaseAsset*>* getAssetMap();

   private:
    std::map<std::string, BaseAsset*>* assetMap;
};
#endif

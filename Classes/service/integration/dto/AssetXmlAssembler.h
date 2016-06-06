//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef AssetXmlAssembler_h
#define AssetXmlAssembler_h

// stl
#include <vector>

// service
#include "BaseAssembler.h"
#include "TAssetTable.h"

class AssetXmlAssembler : public BaseAssembler<TAssetTable> {
   public:
    AssetXmlAssembler(std::string xml);
    virtual ~AssetXmlAssembler();
    std::vector<TAssetTable> writeToVector() override;

   private:
    std::string xml;
};

#endif

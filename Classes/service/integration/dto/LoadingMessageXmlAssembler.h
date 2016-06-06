//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LoadingMessageXmlAssembler_h
#define LoadingMessageXmlAssembler_h

// stl
#include <vector>
#include <string>

// service
#include "BaseAssembler.h"

class LoadingMessageXmlAssembler : public BaseAssembler<std::string> {
   public:
    LoadingMessageXmlAssembler(std::string settingFilePath);
    virtual ~LoadingMessageXmlAssembler();
    std::vector<std::string> writeToVector() override;

   private:
    std::string configFilePath;
};

#endif

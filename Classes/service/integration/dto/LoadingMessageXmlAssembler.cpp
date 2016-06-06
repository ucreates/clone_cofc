//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// cocos2d
#include "cocos2d.h"
#include "external/tinyxml2/tinyxml2.h"

// service
#include "LoadingMessageXmlAssembler.h"

// utility
#include "StringUtility.h"

using namespace cocos2d;
using namespace tinyxml2;

LoadingMessageXmlAssembler::LoadingMessageXmlAssembler(std::string configFilePath) { this->configFilePath = configFilePath; }

LoadingMessageXmlAssembler::~LoadingMessageXmlAssembler() {}

std::vector<std::string> LoadingMessageXmlAssembler::writeToVector() {
    std::vector<std::string> ret;
    XMLDocument doc;
    std::string filePath = FileUtils::getInstance()->fullPathForFilename(this->configFilePath.c_str());
    Data content = FileUtils::getInstance()->getDataFromFile(filePath.c_str());
    XMLError pret = doc.Parse((const char*)content.getBytes(), content.getSize());
    if (XML_NO_ERROR != pret) {
        return ret;
    }

    std::list<std::string> sanitizeTargetList;
    sanitizeTargetList.push_back("\r");
    sanitizeTargetList.push_back("\n");
    sanitizeTargetList.push_back(" ");
    XMLElement* rootElement = doc.RootElement();
    for (XMLElement* element = rootElement->FirstChildElement("title"); element != NULL; element = element->NextSiblingElement("title")) {
        std::string title = element->GetText();
        title = StringUtility::replace(title, sanitizeTargetList, "");
        ret.push_back(title);
    }
    return ret;
}

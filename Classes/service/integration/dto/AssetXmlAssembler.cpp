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
#include <algorithm>
// cocos2d
#include "cocos2d.h"
#include "external/tinyxml2/tinyxml2.h"
// utility
#include "StringUtility.h"
// service
#include "AssetXmlAssembler.h"
#include "TAssetTable.h"
using namespace cocos2d;
using namespace tinyxml2;
AssetXmlAssembler::AssetXmlAssembler(std::string xml) { this->xml = xml; }
AssetXmlAssembler::~AssetXmlAssembler() {}
std::vector<TAssetTable> AssetXmlAssembler::writeToVector() {
    std::vector<TAssetTable> ret;
    XMLDocument doc;
    XMLError pret = doc.Parse(this->xml.c_str());
    if (XML_NO_ERROR != pret) {
        return ret;
    }
    XMLElement* rootElement = doc.FirstChildElement("resource");
    if (NULL != rootElement) {
        std::list<std::string> sanitizeTargetList;
        sanitizeTargetList.push_back("\r");
        sanitizeTargetList.push_back("\n");
        sanitizeTargetList.push_back(" ");
        for (XMLElement* element = rootElement->FirstChildElement("asset"); element != NULL; element = element->NextSiblingElement("asset")) {
            std::string name = element->FirstChildElement("name")->GetText();
            std::string type = element->FirstChildElement("type")->GetText();
            std::string path = element->FirstChildElement("path")->GetText();
            name = StringUtility::replace(name, sanitizeTargetList, "");
            type = StringUtility::replace(type, sanitizeTargetList, "");
            path = StringUtility::replace(path, sanitizeTargetList, "");
            TAssetTable record;
            record.name = name;
            record.type = type;
            record.path = path;
            ret.push_back(record);
        }
    }
    return ret;
}

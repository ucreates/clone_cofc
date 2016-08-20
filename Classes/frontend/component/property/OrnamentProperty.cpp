//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// geography
#include "GeographicGateway.h"
#include "OrnamentProperty.h"
using namespace cocos2d;
OrnamentProperty::OrnamentProperty(std::string name, int id, std::string ornamentType, float xscale, float yscale, float zscale) {
    this->name = name;
    this->id = id;
    this->type = "ornament";
    this->ornamentType = ornamentType;
    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicSize* size = gateway->getSize();
    this->addressScale = new Address(ceilf(xscale), ceilf(yscale), ceilf(zscale));
    float ow = size->unitSize.width * xscale;
    float oh = size->unitSize.height * yscale;
    this->scale = new Scale(Size(ow, oh));
}
OrnamentProperty::~OrnamentProperty() {
    CC_SAFE_DELETE(this->addressScale);
    CC_SAFE_DELETE(this->scale);
}
Scale* OrnamentProperty::getScale() { return this->scale; }
Address* OrnamentProperty::getAddressScale() { return this->addressScale; }
std::string OrnamentProperty::getOrnamentType() { return this->ornamentType; }
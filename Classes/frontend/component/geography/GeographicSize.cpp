//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "GeographicSize.h"
using namespace cocos2d;

GeographicSize::GeographicSize() : worldAddress(Address(GeographicSize::MAX_COORDINATE_X, GeographicSize::MAX_COORDINATE_Y, GeographicSize::MAX_COORDINATE_Z)), unitSize(Size(35.0f, 35.0f)), unitSpaceSize(Size(0.0f, 0.0f)) {}

GeographicSize::GeographicSize(Address worldAddress, Size unitSize, Size unitSpaceSize) {
    this->unitSize = unitSize;
    this->unitHalfSize = Size(unitSize.width / 2, unitSize.height / 2);
    this->unitSpaceSize = unitSpaceSize;
    this->worldAddress = worldAddress;

    float width = worldAddress.x * unitSize.width;
    float height = worldAddress.y * unitSize.height;
    this->worldSize = Size(width, height);
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// validator
#include "AddressRangeValidator.h"

// geographic
#include "GeographicGateway.h"
#include "GeographicSize.h"

AddressRangeValidator::AddressRangeValidator() {}

AddressRangeValidator::~AddressRangeValidator() {}

bool AddressRangeValidator::isValid() {
    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicSize* size = gateway->getSize();
    int x = this->address.x;
    int y = this->address.y;

    if (0 <= x && x < size->worldAddress.x && 0 <= y && y < size->worldAddress.y) {
        return true;
    }
    return false;
}

void AddressRangeValidator::setProperty(Address address) { this->address = address; }

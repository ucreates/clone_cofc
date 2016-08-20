//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Address_h
#define Address_h
// stl
#include <string>
// utility
#include "ConvertUtility.h"
class Address {
   public:
    int x;
    int y;
    int z;
    static const Address ZERO;
    inline Address() : Address(0, 0, 0) {}
    inline Address(int x, int y) : Address(x, y, 0) {}
    inline Address(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    inline std::string toString(bool containZOrder = false) {
        std::string result = ConvertUtility::toString(this->x) + ", " + ConvertUtility::toString(this->y);
        if (false != containZOrder) {
            result += ", " + ConvertUtility::toString(this->z);
        }
        return result;
    }
    inline bool operator==(const Address& address) const { return (this->x == address.x && this->y == address.y && this->z == address.z); }
};
#endif

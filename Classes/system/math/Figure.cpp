//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// math
#include "Figure.h"
int Figure::count(int number, int count) {
    int tmpCount = count;
    int ret = number / 10;
    if (ret <= 0) {
        return tmpCount;
    } else {
        return Figure::count(ret, ++tmpCount);
    }
}
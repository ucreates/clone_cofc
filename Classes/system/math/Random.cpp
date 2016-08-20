//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// standard
#include <stdlib.h>
// math
#include "Random.h"
int Random::create(int number, bool forArray) {
    int ret = (rand() % number + 1);
    if (false != forArray) {
        ret = ret - 1;
        if (ret < 0) {
            ret = 0;
        }
    }
    return ret;
}
int Random::create(int min, int max, bool forArray) {
    if (max <= min) {
        return 0;
    }
    int num = max - min;
    int ret = Random::create(num, forArray);
    ret = ret + min;
    return ret;
}

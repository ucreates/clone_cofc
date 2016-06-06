//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "GeographicDepth.h"

int GeographicDepth::create(int x, int y, int z, int diffHeightX, int diffHeightY) {
    int depth = z * y * diffHeightY + x * diffHeightX;
    return depth;
}
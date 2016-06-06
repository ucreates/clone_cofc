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

// math
#include "Number.h"

bool Number::isNumeric(std::string val) { return std::all_of(val.cbegin(), val.cend(), ::isdigit); }
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "GeographicSlope.h"
GeographicSlope::GeographicSlope() : column(37.0f), row(323.0f) {}
GeographicSlope::GeographicSlope(float coldegree, float rowdegree) { this->update(coldegree, rowdegree); }
void GeographicSlope::update(float coldegree, float rowdegree) {
    this->column = Slope(coldegree);
    this->row = Slope(rowdegree);
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Macro_h
#define Macro_h

#include <typeinfo>
#define ENTER printf("ENTER::%s::%s, at %d ,in %s\n", typeid(this).name(), __FUNCTION__, __LINE__, __FILE__)
#define LEAVE printf("LEAVE::%s::%s, at %d ,in %s\n", typeid(this).name(), __FUNCTION__, __LINE__, __FILE__)
#define DEBUG_INT(name, val) printf("DEBUG_INT::%s::%d\n", name, val)
#define DEBUG_FLOAT(name, val) printf("DEBUG_FLOAT::%s::%f\n", name, val)
#define DEBUG_VECTOR2(name, val) printf("DEBUG_VECTOR2::%s::(x, y)=>(%f, %f)\n", name, val.x, val.y)
#define DEBUG_ADDRESS(name, val) printf("DEBUG_VECTOR2::%s::(x, y, z)=>(%d, %d, %d)\n", name, val.x, val.y, val.z)
#define DEBUG_POINT(name, val) printf("DEBUG_POINT::%s::(x, y)=>(%f, %f)\n", name, val.x, val.y)
#define DEBUG_SIZE(name, val) printf("DEBUG_SIZE::%s::(w, h)=>(%f, %f)\n", name, val.width, val.height)
#define DEBUG_GLUBYTE(name, val) printf("DEBUG_GLUBYTE::%s::%d\n", name, val)
#define DEBUG_RECT(name, val) printf("DEBUG_RECT::%s::(sx, sy, ex, ey)=>(%f, %f, %f, %f)\n", name, val.getMinX(), val.getMinY(), val.getMaxX(), val.getMaxY())
#endif
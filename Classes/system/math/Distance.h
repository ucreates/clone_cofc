//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Distance_h
#define Distance_h

// cocos2d
#include "cocos2d.h"

// entity
#include "Address.h"
#include "Transform.h"
#include "Position.h"

// geography
#include "GeographicNode.h"

class Distance {
   public:
    static float create(cocos2d::Vec2 start, cocos2d::Vec2 goal);
    static float create(Position start, Position goal);
    static float create(Transform* transform, GeographicNode* node);
    static float create(cocos2d::Size screenSize);
    static int create(Address start, Address goal);
};

#endif

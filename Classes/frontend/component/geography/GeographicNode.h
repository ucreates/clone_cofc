//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef geographicNodeStruct_h
#define geographicNodeStruct_h

#include "cocos2d.h"
#include "Address.h"
#include "Scale.h"

// collider
#include "BaseCollider.h"

class BaseCollider;

class GeographicNode {
   public:
    unsigned int geographicId;
    unsigned int parentGeographicId;
    int depth;
    unsigned short type;
    cocos2d::Vec2 position;
    Address address;
    Scale* scale;
    BaseCollider* collider;
    GeographicNode();
    ~GeographicNode();
    void dump(cocos2d::Layer* layer, int depth);
};

#endif

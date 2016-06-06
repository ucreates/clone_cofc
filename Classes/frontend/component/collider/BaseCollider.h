//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseCollider_h
#define BaseCollider_h

#include "cocos2d.h"

// behaviour
#include "BaseBehaviour.h"

// geography
#include "GeographicNode.h"

class BaseBehaviour;
class GeographicNode;
class BaseCollider {
   public:
    BaseCollider();
    BaseCollider(BaseBehaviour* behaviour);
    BaseCollider(GeographicNode* node);
    BaseCollider(BaseBehaviour* behaviour, GeographicNode* node);
    virtual ~BaseCollider();
    bool isHit(BaseBehaviour* behaviour);
    bool isHit(cocos2d::Vec2 position);
    bool isHit(float x, float y);
    virtual cocos2d::Node* getGizmo();

   protected:
    BaseBehaviour* behaviour;
    GeographicNode* node;
    virtual bool isBehaviourHit(BaseBehaviour* behaviour);
    virtual bool isBehaviourHit(float x, float y);
    virtual bool isNodeHit(BaseBehaviour* behaviour);
    virtual bool isNodeHit(float x, float y);
};

#endif

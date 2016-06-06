//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef RectCollider_h
#define RectCollider_h
#include "cocos2d.h"

// behaviour
#include "BaseBehaviour.h"

// geography
#include "GeographicNode.h"

// collider
#include "BaseCollider.h"

class BaseBehaviour;
class GeographicNode;

class RectCollider : public BaseCollider {
   public:
    RectCollider();
    RectCollider(BaseBehaviour* behaviour);
    RectCollider(GeographicNode* node);
    RectCollider(BaseBehaviour* behaviour, GeographicNode* node);
    virtual ~RectCollider();
    void addLayer(cocos2d::Layer* layer, int depth);

   protected:
    bool isBehaviourHit(BaseBehaviour* behaviour) override;
    bool isNodeHit(BaseBehaviour* behaviour) override;
};

#endif
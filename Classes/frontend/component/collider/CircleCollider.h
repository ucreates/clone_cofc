//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef CircleCollider_h
#define CircleCollider_h

#include "cocos2d.h"

// behaviour
#include "BaseBehaviour.h"

// collider
#include "BaseCollider.h"

class BaseBehaviour;
class GeographicNode;
class BaseCollider;

class CircleCollider : public BaseCollider {
   public:
    CircleCollider();
    CircleCollider(BaseBehaviour* behaviour);
    CircleCollider(GeographicNode* node);
    CircleCollider(BaseBehaviour* behaviour, GeographicNode* node);
    virtual ~CircleCollider();
    cocos2d::Node* getGizmo() override;

   protected:
    bool isBehaviourHit(BaseBehaviour* behaviour) override;
    bool isNodeHit(BaseBehaviour* behaviour) override;
    bool isNodeHit(float x, float y) override;

   private:
    float radius;
};

#endif

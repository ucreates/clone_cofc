//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef EllipseCollider_h
#define EllipseCollider_h

#include "cocos2d.h"

// behaviour
#include "BaseBehaviour.h"

// collider
#include "BaseCollider.h"

class EllipseCollider : public BaseCollider {
   public:
    EllipseCollider();
    EllipseCollider(BaseBehaviour* behaviour);
    EllipseCollider(GeographicNode* node);
    EllipseCollider(BaseBehaviour* behaviour, GeographicNode* node);
    virtual ~EllipseCollider();

   protected:
    bool isBehaviourHit(BaseBehaviour* behaviour) override;
    bool isNodeHit(BaseBehaviour* behaviour) override;
};

#endif

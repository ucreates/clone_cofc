//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseBarrierBehaviour_h
#define BaseBarrierBehaviour_h

// stl
#include <vector>

// behaviour
#include "BaseOrnamentBehaviour.h"
#include "BarrierLifeGaugeBehaviour.h"

#include "GeographicNode.h"
#include "BaseStrategy.h"

class BaseBarrierBehaviour : public BaseOrnamentBehaviour {
   public:
    BarrierLifeGaugeBehaviour* lifeGuage;
    BaseBarrierBehaviour();
    virtual ~BaseBarrierBehaviour();
    void onCollision() override;
    std::vector<GeographicNode*> getGeographicNodeVector();
    void setGeographicNodeVector(std::vector<GeographicNode*> nodeVector);
    void clearGeographicNodeVector();

   private:
    BaseStrategy* damageStrategy;
    std::vector<GeographicNode*> nodeVector;
};

#endif

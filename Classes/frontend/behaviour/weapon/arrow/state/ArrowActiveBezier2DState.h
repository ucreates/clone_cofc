//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ArrowActiveBezier2DState_h
#define ArrowActiveBezier2DState_h

// state
#include "FiniteState.h"

// behaviour
#include "ArrowBehaviour.h"

// asset
#include "BaseRenderAsset.h"

class ArrowBehaviour;
class ArrowActiveBezier2DState : public FiniteState<ArrowBehaviour> {
   public:
    ArrowActiveBezier2DState();
    virtual ~ArrowActiveBezier2DState();
    void create() override;
    void update(float delta) override;

   private:
    constexpr static const float VECTOR_POWER = 50.0f;
    constexpr static const float MOVE_SPEED = 300.0f;
    constexpr static const float HEIGHT_RATE = 0.5f;
    constexpr static const float DEFAULT_DEGREE = 90.0f;
    cocos2d::Vec2 control;
    cocos2d::Vec2 position;
    BaseRenderAsset* asset;
    float moveTime;
};

#endif

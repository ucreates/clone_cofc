//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef ArrowActiveBezier3DState_h
#define ArrowActiveBezier3DState_h

// cocos2d
#include "cocos2d.h"

// state
#include "FiniteState.h"

// behaviour
#include "ArrowBehaviour.h"

// asset
#include "BaseRenderAsset.h"

class ArrowBehaviour;
class ArrowActiveBezier3DState : public FiniteState<ArrowBehaviour> {
   public:
    ArrowActiveBezier3DState();
    virtual ~ArrowActiveBezier3DState();
    void create() override;
    void update(float delta) override;

   private:
    constexpr static const float VECTOR_POWER = 50.0f;
    constexpr static const float MOVE_SPEED = 300.0f;
    constexpr static const float HEIGHT_RATE = 0.75f;
    constexpr static const float DEFAULT_DEGREE = 90.0f;
    cocos2d::Vec2 control1;
    cocos2d::Vec2 control2;
    cocos2d::Vec2 position;
    cocos2d::Vec2 start;
    BaseRenderAsset* asset;
    float moveTime;
};

#endif

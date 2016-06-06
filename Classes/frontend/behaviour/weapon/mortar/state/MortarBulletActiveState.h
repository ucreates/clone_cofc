//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef MortarBulletActiveState_h
#define MortarBulletActiveState_h

// stl
#include <vector>

// cocos2d
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

// state
#include "FiniteState.h"

// behaviour
#include "MortarBulletBehaviour.h"

// asset
#include "BaseRenderAsset.h"
#include "BaseStrategy.h"

class MortarBulletBehaviour;
class MortarBulletActiveState : public FiniteState<MortarBulletBehaviour> {
   public:
    MortarBulletActiveState();
    virtual ~MortarBulletActiveState();
    void create() override;
    void update(float delta) override;

   private:
    constexpr static const float SHOT_HEIGHT = 51.35f;
    constexpr static const float MOVE_SPEED = 150.0f;
    constexpr static const float HEIGHT_RATE = 5.0f;
    constexpr static const float DEFAULT_DEGREE = 90.0f;
    cocos2d::Vec2 start;
    cocos2d::Vec2 control;
    cocos2d::Vec2 position;
    BaseRenderAsset* asset;
    BaseStrategy* damageStrategy;
    float moveTime;
    bool enableShot;
};

#endif

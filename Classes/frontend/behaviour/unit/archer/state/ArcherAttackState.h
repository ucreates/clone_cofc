//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef ArcherAttackState_h
#define ArcherAttackState_h
// stl
#include <vector>
// cocos2d
#include "cocos2d.h"
// state
#include "FiniteState.h"
// behaviour
#include "ArcherBehaviour.h"
#include "BaseOrnamentBehaviour.h"
#include "ArrowBehaviour.h"
// frame
#include "TimeLine.h"
// notify
#include "Parameter.h"
#include "BaseStrategy.h"
class ArcherBehaviour;
class ArcherAttackState : public FiniteState<ArcherBehaviour> {
   public:
    ArcherAttackState(int ownerId);
    virtual ~ArcherAttackState();
    void create(Parameter* parameter) override;
    void update(float delta = 0.0f) override;
   private:
    const int ENABLE_ATTACK_DISTANCE = 1;
    const int STOCKED_ARRROW_NUMBER = 1;
    constexpr static const float WAIT_TIME = 1.0f;
    BaseRenderAsset* asset;
    GeographicNode* currentNode;
    GeographicNode* barrierNode;
    int targetBarrierId;
    BaseOrnamentBehaviour* targetBarrier;
    std::vector<ArrowBehaviour*> stockedArrowVector;
    int shotedArrowCount;
    bool destroy;
    BaseStrategy* damageStrategy;
    void changeDirection();
    void selectAttackAnimation(std::string animationNamem, bool transform);
};
#endif

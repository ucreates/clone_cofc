//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TowerArcherAttackState_h
#define TowerArcherAttackState_h
// cocos2d
#include "cocos2d.h"
// state
#include "FiniteState.h"
// behaviour
#include "TowerArcherBehaviour.h"
#include "ArrowBehaviour.h"
// notify
#include "Parameter.h"
#include "Direction.h"
#include "BaseStrategy.h"
class TowerArcherBehaviour;
class TowerArcherAttackState : public FiniteState<TowerArcherBehaviour> {
   public:
    TowerArcherAttackState(int ownerId);
    virtual ~TowerArcherAttackState();
    void create(Parameter* parameter) override;
    void update(float delta = 0.0f) override;
   private:
    const int ENABLE_ATTACK_DISTANCE = 1;
    constexpr static const float WAIT_TIME = 2.0f;
    BaseRenderAsset* asset;
    int targetId;
    bool enableSearch;
    BaseBehaviour* target;
    Direction::DIRECT direction;
    std::vector<ArrowBehaviour*> stockedArrowVector;
    BaseStrategy* damageStrategy;
    void changeDirection();
    void selectAttackAnimation(std::string animationNamem, bool transform);
};
#endif

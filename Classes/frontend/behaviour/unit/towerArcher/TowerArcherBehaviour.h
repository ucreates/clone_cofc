//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TowerTowerArcherBehaviour_h
#define TowerTowerArcherBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseUnitBehaviour.h"
// state
#include "FiniteStateMachine.h"
#include "IFiniteStateMachine.h"
#include "TowerArcherSearchState.h"
#include "TowerArcherAttackState.h"
#include "TowerArcherWinState.h"
#include "TowerArcherLoseState.h"
#include "UnitWinState.h"
#include "UnitLoseState.h"
// notify
#include "INotify.h"
#include "Parameter.h"
#include "NotifyMessage.h"
class TowerArcherSearchState;
class TowerArcherAttackState;
class TowerArcherWinState;
class TowerArcherLoseState;
class TowerArcherBehaviour : public BaseUnitBehaviour, public IFiniteStateMachine<TowerArcherBehaviour>, public INotify {
    friend UnitLoseState<TowerArcherBehaviour>;
    friend UnitWinState<TowerArcherBehaviour>;
    friend TowerArcherSearchState;
    friend TowerArcherAttackState;
    friend TowerArcherWinState;
    friend TowerArcherLoseState;
   public:
    TowerArcherBehaviour();
    virtual ~TowerArcherBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
    void onUpdate(float delta = 0.0f) override;
    void onNotify(NotifyMessage notifyMessage, Parameter* parameter = NULL) override;
};
#endif
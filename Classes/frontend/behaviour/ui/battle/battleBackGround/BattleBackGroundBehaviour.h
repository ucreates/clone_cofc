//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BattleBackGroundBehaviour_h
#define BattleBackGroundBehaviour_h

#include "BaseBehaviour.h"

class BattleBackGroundBehaviour : public BaseBehaviour {
   public:
    BattleBackGroundBehaviour();
    virtual ~BattleBackGroundBehaviour();
    void onCreate(cocos2d::Layer* layer) override;
};

#endif

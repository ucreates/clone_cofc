//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseCommand_h
#define BaseCommand_h
#include "BaseBehaviour.h"
class BaseCommand {
   public:
    BaseCommand();
    virtual ~BaseCommand();
    void initialize(BaseBehaviour* behaviour, cocos2d::Layer* layer);
    void initialize(BaseBehaviour* behaviour, cocos2d::Layer* layer, int depth);
    void initialize(BaseBehaviour* behaviour, cocos2d::Layer* layer, Position position);
    virtual void execute(BaseBehaviour* behaviour, float delta);
};
#endif

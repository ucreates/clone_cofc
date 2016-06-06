//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef EffectCommand_h
#define EffectCommand_h

#include "BaseCommand.h"
#include "BaseBehaviour.h"

class EffectCommand : public BaseCommand {
   public:
    EffectCommand();
    virtual ~EffectCommand();
    void execute(BaseBehaviour* behaviour, float delta) override;
};

#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef UnitCommand_h
#define UnitCommand_h

#include "BaseCommand.h"
#include "BaseBehaviour.h"

class UnitCommand : public BaseCommand {
   public:
    UnitCommand();
    virtual ~UnitCommand();
    void execute(BaseBehaviour* behaviour, float delta) override;
};

#endif

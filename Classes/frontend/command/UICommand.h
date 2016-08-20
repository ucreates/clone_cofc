//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UICommand_h
#define UICommand_h
#include "BaseCommand.h"
#include "BaseBehaviour.h"
class UICommand : public BaseCommand {
   public:
    UICommand();
    virtual ~UICommand();
    void execute(BaseBehaviour* behaviour, float delta) override;
};
#endif

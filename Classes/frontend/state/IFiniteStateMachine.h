//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef IFiniteStateMachine_h
#define IFiniteStateMachine_h
#include "FiniteStateMachine.h"
template <class T>
class IFiniteStateMachine {
   public:
    IFiniteStateMachine() {}
    virtual ~IFiniteStateMachine() { CC_SAFE_DELETE(this->stateMachine); }
    FiniteStateMachine<T>* getStateMachine() { return this->stateMachine; }
   protected:
    FiniteStateMachine<T>* stateMachine;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BarrierDestroyState_h
#define BarrierDestroyState_h
#include "TOverAllTable.h"
template <class T>
class BarrierDestroyState {
   public:
    BarrierDestroyState();
    ~BarrierDestroyState();
   protected:
    void notifyOverAll(TOverAllTable overAll);
};
#endif

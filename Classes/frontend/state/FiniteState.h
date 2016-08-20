//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef FiniteState_h
#define FiniteState_h
#include "Parameter.h"
#include "TimeLine.h"
template <class T>
class FiniteState {
   public:
    bool persistence;
    bool complete;
    bool wait;
    T* owner;
    inline FiniteState() {
        this->persistence = false;
        this->complete = false;
        this->frame = new TimeLine();
        this->owner = NULL;
        this->wait = false;
    }
    inline virtual ~FiniteState() { CC_SAFE_DELETE(this->frame); }
    inline virtual void create() { return; }
    inline virtual void create(Parameter* parameter) { return; }
    inline virtual void update(float delta) { return; }
    inline virtual void reset() { return; }
    inline void setOwner(T* owner) {
        this->owner = owner;
        return;
    }
   protected:
    TimeLine* frame;
};
#endif

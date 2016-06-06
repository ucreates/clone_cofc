//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef FiniteStateEntity_h
#define FiniteStateEntity_h

#include "FiniteState.h"

template <class T>
class FiniteStateEntity {
   public:
    bool isNewState;
    FiniteState<T>* state;
    std::string currentStateName;
    std::string previousStateName;
    std::string nextStateName;

    inline FiniteStateEntity() {
        this->state = NULL;
        this->currentStateName = "";
        this->previousStateName = "";
        this->nextStateName = "";
        this->isNewState = false;
    }

    inline void update(std::string nextStateName, FiniteState<T>* nextState) {
        this->previousStateName = this->currentStateName;
        this->currentStateName = nextStateName;
        this->state = nextState;
        this->isNewState = true;
    }
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseTransitionState_h
#define BaseTransitionState_h
template <class T>
class BaseTransitionState {
   public:
    BaseTransitionState();
    virtual ~BaseTransitionState();
    void transition(T* owner, int sceneId);
};
#endif

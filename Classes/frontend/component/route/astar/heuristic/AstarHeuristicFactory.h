//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef AstarHeuristicFactory_h
#define AstarHeuristicFactory_h
#include "BaseAstarHeuristic.h"
class AstarHeuristicFactory {
   public:
    static BaseAstarHeuristic* factoryMethod(int heuristicId);
};
#endif

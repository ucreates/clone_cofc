//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BehaviourMapper_h
#define BehaviourMapper_h

// stl
#include <map>

// cocos2d
#include "cocos2d.h"

// behaviour
#include "BaseBehaviour.h"

class BehaviourMapper {
   public:
    static BehaviourMapper* getInstance();
    void addMappingList(BaseBehaviour* behaviour, Position position);
    void addMappingList(BaseBehaviour* behaviour, cocos2d::Vec2 position, int depth);
    void map(cocos2d::Layer* layer);
    void clear();
    static void destroy();

   private:
    std::map<BaseBehaviour*, Position> mappingBehaviourMap;
    static BehaviourMapper* instance;
    BehaviourMapper();
};

#endif

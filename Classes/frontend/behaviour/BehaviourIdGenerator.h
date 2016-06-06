//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BehaviourIdGenerator_h
#define BehaviourIdGenerator_h

class BehaviourIdGenerator {
   public:
    static BehaviourIdGenerator* getInstance();
    int getId();
    void clear();
    static void destroy();

   private:
    unsigned int id;
    static BehaviourIdGenerator* instance;
    BehaviourIdGenerator();
};

#endif

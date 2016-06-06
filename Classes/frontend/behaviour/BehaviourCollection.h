//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BehaviourCollection_h
#define BehaviourCollection_h

// stl
#include <vector>

// behaviour
#include "BaseBehaviour.h"
#include "BaseOrnamentBehaviour.h"
#include "BaseUnitBehaviour.h"

// address
#include "Address.h"

class BehaviourCollection {
   public:
    ~BehaviourCollection();
    static BehaviourCollection* getInstance();
    int getCount(std::string behaviourType);
    int getOrnamentCount(std::string ornamentName);
    int getBarrierCount();
    std::vector<BaseBehaviour*>* getBehaviourVector(std::string type);
    BaseBehaviour* getUnitCache(std::string unitType);
    void add(BaseBehaviour* behaviour);
    void addUnitCache(BaseBehaviour* behaviour);
    void addClearVector(BaseBehaviour* behaviour);
    BaseOrnamentBehaviour* findBarrierByAddress(Address address, bool ignoreNotBarrier = false);
    std::vector<BaseUnitBehaviour*> findUnitByAddress(int radius, Address address);
    std::vector<BaseOrnamentBehaviour*> findBarrierByAddress(int radius, Address address);
    std::vector<std::string> getBehaviourTypeVector();
    GeographicNode* findBarrierByPosition(GeographicNode* startNode, bool ignoreNotBarrier);
    GeographicNode* findBarrierByOrnamentType(GeographicNode* startNode, std::string ornamentType);

    void clear();
    static void destroy();

   private:
    std::vector<BaseBehaviour*> unitCacheBehaviourVector;
    std::vector<BaseBehaviour*>* unitBehaviourVector;
    std::vector<BaseBehaviour*>* ornamentBehaviourVector;
    std::vector<BaseBehaviour*>* weaponBehaviourVector;
    std::vector<BaseBehaviour*>* effectBehaviourVector;
    std::vector<BaseBehaviour*>* uiBehaviourVector;
    std::vector<BaseBehaviour*>* bgBehaviourVector;
    std::vector<BaseBehaviour*> clearVector;
    std::vector<std::string> beheaviourTypeVector;
    static BehaviourCollection* instance;
    BehaviourCollection();
    void clear(std::vector<BaseBehaviour*>* behaviourVector);
};

#endif

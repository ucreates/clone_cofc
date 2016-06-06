//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BehaviourCollection.h"
#include "Distance.h"
#include "BaseBarrierBehaviour.h"
#include "BarrierBehaviourType.h"

using namespace std;
using namespace cocos2d;

BehaviourCollection* BehaviourCollection::instance = new BehaviourCollection();

BehaviourCollection::BehaviourCollection() {
    this->unitBehaviourVector = new std::vector<BaseBehaviour*>();
    this->ornamentBehaviourVector = new std::vector<BaseBehaviour*>();
    this->weaponBehaviourVector = new std::vector<BaseBehaviour*>();
    this->effectBehaviourVector = new std::vector<BaseBehaviour*>();
    this->uiBehaviourVector = new std::vector<BaseBehaviour*>();
    this->bgBehaviourVector = new std::vector<BaseBehaviour*>();
    this->beheaviourTypeVector.push_back("unit");
    this->beheaviourTypeVector.push_back("ornament");
    this->beheaviourTypeVector.push_back("weapon");
    this->beheaviourTypeVector.push_back("effect");
    this->beheaviourTypeVector.push_back("ui");
    this->beheaviourTypeVector.push_back("background");
}

BehaviourCollection::~BehaviourCollection() {
    this->clear();
    CC_SAFE_DELETE(this->unitBehaviourVector);
    CC_SAFE_DELETE(this->ornamentBehaviourVector);
    CC_SAFE_DELETE(this->weaponBehaviourVector);
    CC_SAFE_DELETE(this->effectBehaviourVector);
    CC_SAFE_DELETE(this->uiBehaviourVector);
    CC_SAFE_DELETE(this->bgBehaviourVector);
}

BehaviourCollection* BehaviourCollection::getInstance() {
    if (NULL == BehaviourCollection::instance) {
        BehaviourCollection::instance = new BehaviourCollection();
    }
    return BehaviourCollection::instance;
}

std::vector<BaseBehaviour*>* BehaviourCollection::getBehaviourVector(std::string type) {
    std::vector<BaseBehaviour*>* ret = NULL;
    if ("unit" == type) {
        ret = this->unitBehaviourVector;
    } else if ("ornament" == type) {
        ret = this->ornamentBehaviourVector;
    } else if ("weapon" == type) {
        ret = this->weaponBehaviourVector;
    } else if ("effect" == type) {
        ret = this->effectBehaviourVector;
    } else if ("ui" == type) {
        ret = this->uiBehaviourVector;
    } else if ("background" == type) {
        ret = this->bgBehaviourVector;
    }
    return ret;
}

void BehaviourCollection::add(BaseBehaviour* behaviour) {
    std::string type = behaviour->getProperty()->getType();
    if ("unit" == type) {
        this->unitBehaviourVector->push_back(behaviour);
    } else if ("ornament" == type) {
        this->ornamentBehaviourVector->push_back(behaviour);
    } else if ("weapon" == type) {
        this->weaponBehaviourVector->push_back(behaviour);
    } else if ("effect" == type) {
        this->effectBehaviourVector->push_back(behaviour);
    } else if ("ui" == type) {
        this->uiBehaviourVector->push_back(behaviour);
    } else if ("background" == type) {
        this->bgBehaviourVector->push_back(behaviour);
    }
}

void BehaviourCollection::addUnitCache(BaseBehaviour* behaviour) { this->unitCacheBehaviourVector.push_back(behaviour); }

void BehaviourCollection::addClearVector(BaseBehaviour* behaviour) { this->clearVector.push_back(behaviour); }

int BehaviourCollection::getCount(std::string behaviourType) {
    std::vector<BaseBehaviour*>* behaviourVector = this->getBehaviourVector(behaviourType);
    int count = behaviourVector->size();
    return count;
}

int BehaviourCollection::getOrnamentCount(std::string ornamentName) {
    int count = 0;
    for (std::vector<BaseBehaviour*>::iterator it = this->ornamentBehaviourVector->begin(); it != this->ornamentBehaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        if (NULL == behaviour) {
            continue;
        }

        std::string name = behaviour->getProperty()->getName();
        if (name == ornamentName) {
            count++;
        }
    }
    return count;
}

int BehaviourCollection::getBarrierCount() {
    int count = 0;
    for (std::vector<BaseBehaviour*>::iterator it = this->ornamentBehaviourVector->begin(); it != this->ornamentBehaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        if (NULL == behaviour) {
            continue;
        }

        OrnamentProperty* property = (OrnamentProperty*)behaviour->getProperty();
        std::string ornamentType = property->getOrnamentType();
        if ("other" == ornamentType || "wall" == ornamentType) {
            continue;
        }
        count++;
    }
    return count;
}

BaseBehaviour* BehaviourCollection::getUnitCache(std::string unitType) {
    BaseBehaviour* unit = NULL;
    for (std::vector<BaseBehaviour*>::iterator it = this->unitCacheBehaviourVector.begin(); it != this->unitCacheBehaviourVector.end(); it++) {
        if (unitType == (*it)->getProperty()->getName()) {
            unit = (*it);
            it = this->unitCacheBehaviourVector.erase(it);
            break;
        }
    }
    return unit;
}

std::vector<std::string> BehaviourCollection::getBehaviourTypeVector() { return this->beheaviourTypeVector; }

BaseOrnamentBehaviour* BehaviourCollection::findBarrierByAddress(Address address, bool ignoreNotBarrier) {
    for (std::vector<BaseBehaviour*>::iterator it = this->ornamentBehaviourVector->begin(); it != this->ornamentBehaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        if (NULL == behaviour) {
            continue;
        }

        std::string type = behaviour->getProperty()->getType();
        BaseBarrierBehaviour* barrier = (BaseBarrierBehaviour*)behaviour;
        std::vector<GeographicNode*> tmpNodeVector = barrier->getGeographicNodeVector();
        for (std::vector<GeographicNode*>::iterator nt = tmpNodeVector.begin(); nt != tmpNodeVector.end(); nt++) {
            GeographicNode* tmpNode = (*nt);

            if (false != ignoreNotBarrier && (BarrierBehaviourType::None == tmpNode->type || BarrierBehaviourType::WoodFenceV == tmpNode->type || BarrierBehaviourType::WoodFenceH == tmpNode->type)) {
                continue;
            }

            if (tmpNode->address == address) {
                return barrier;
            }
        }
    }
    return NULL;
}

std::vector<BaseUnitBehaviour*> BehaviourCollection::findUnitByAddress(int radius, Address address) {
    std::vector<BaseUnitBehaviour*> unitVector;
    for (std::vector<BaseBehaviour*>::iterator it = this->unitBehaviourVector->begin(); it != this->unitBehaviourVector->end(); it++) {
        BaseUnitBehaviour* behaviour = (BaseUnitBehaviour*)(*it);
        if (NULL == behaviour) {
            continue;
        }

        GeographicNode* node = behaviour->getGeographicNode();
        if (NULL == node) {
            continue;
        }

        int distance = Distance::create(address, node->address);
        if (distance <= radius) {
            unitVector.push_back(behaviour);
        }
    }
    return unitVector;
}

std::vector<BaseOrnamentBehaviour*> BehaviourCollection::findBarrierByAddress(int radius, Address address) {
    std::vector<BaseOrnamentBehaviour*> barrierVector;
    for (std::vector<BaseBehaviour*>::iterator it = this->ornamentBehaviourVector->begin(); it != this->ornamentBehaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        if (NULL == behaviour) {
            continue;
        }

        std::string type = behaviour->getProperty()->getType();
        BaseOrnamentBehaviour* barrier = (BaseOrnamentBehaviour*)behaviour;
        GeographicNode* node = barrier->getGeographicNode();
        int distance = Distance::create(address, node->address);
        if (distance <= radius) {
            barrierVector.push_back(barrier);
        }
    }
    return barrierVector;
}

GeographicNode* BehaviourCollection::findBarrierByPosition(GeographicNode* startNode, bool ignoreNotBarrier) {
    if (NULL == startNode) {
        return NULL;
    }
    int distance = INT_MAX;
    GeographicNode* node = NULL;
    for (std::vector<BaseBehaviour*>::iterator it = this->ornamentBehaviourVector->begin(); it != this->ornamentBehaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        if (NULL == behaviour) {
            continue;
        }

        BaseBarrierBehaviour* barrier = (BaseBarrierBehaviour*)behaviour;
        OrnamentProperty* property = (OrnamentProperty*)barrier->getProperty();
        if ("other" == property->getOrnamentType()) {
            continue;
        }

        std::vector<GeographicNode*> tmpNodeVector = barrier->getGeographicNodeVector();
        for (std::vector<GeographicNode*>::iterator it = tmpNodeVector.begin(); it != tmpNodeVector.end(); it++) {
            GeographicNode* tmpNode = (*it);
            if (false != ignoreNotBarrier && (BarrierBehaviourType::None == tmpNode->type || BarrierBehaviourType::WoodFenceV == tmpNode->type || BarrierBehaviourType::WoodFenceH == tmpNode->type)) {
                continue;
            }

            int tmpDistance = Distance::create(startNode->position, tmpNode->position);
            if (distance >= tmpDistance) {
                distance = tmpDistance;
                node = tmpNode;
            }
        }
    }
    return node;
}

GeographicNode* BehaviourCollection::findBarrierByOrnamentType(GeographicNode* startNode, string ornamentType) {
    if (NULL == startNode) {
        return NULL;
    }

    int distance = INT_MAX;
    GeographicNode* node = NULL;
    OrnamentProperty* property = NULL;
    for (std::vector<BaseBehaviour*>::iterator it = this->ornamentBehaviourVector->begin(); it != this->ornamentBehaviourVector->end(); it++) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        if (NULL == behaviour) {
            continue;
        }

        property = (OrnamentProperty*)behaviour->getProperty();
        std::string tmpOrnamentType = property->getOrnamentType();
        if (ornamentType != tmpOrnamentType) {
            continue;
        }

        BaseBarrierBehaviour* barrier = (BaseBarrierBehaviour*)behaviour;
        std::vector<GeographicNode*> tmpNodeVector = barrier->getGeographicNodeVector();
        for (std::vector<GeographicNode*>::iterator nt = tmpNodeVector.begin(); nt != tmpNodeVector.end(); nt++) {
            GeographicNode* tmpNode = (*nt);
            if (BarrierBehaviourType::None == tmpNode->type) {
                continue;
            }

            int tmpDistance = Distance::create(startNode->position, tmpNode->position);
            if (distance >= tmpDistance) {
                distance = tmpDistance;
                node = tmpNode;
            }
        }
    }
    return node;
}

void BehaviourCollection::clear() {
    this->weaponBehaviourVector->clear();
    this->effectBehaviourVector->clear();
    this->clear(this->unitBehaviourVector);
    this->clear(this->ornamentBehaviourVector);
    this->clear(this->uiBehaviourVector);
    this->clear(this->bgBehaviourVector);
    this->clear(&this->unitCacheBehaviourVector);
    this->clear(&this->clearVector);
    return;
}

void BehaviourCollection::clear(std::vector<BaseBehaviour*>* behaviourVector) {
    for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); ++it) {
        BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
        CC_SAFE_DELETE(behaviour);
    }
    behaviourVector->clear();
}

void BehaviourCollection::destroy() { CC_SAFE_DELETE(BehaviourCollection::instance); }

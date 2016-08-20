//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// geograpy
#include "GeographicGateway.h"
#include "GeographicDepth.h"
#include "BarrierBehaviourFactory.h"
#include "BehaviourCollection.h"
#include "GeographicDataFieldTag.h"
#include "GeographicDataBarrierTag.h"
// device
#include "Screen.h"
// math
#include "Random.h"
#include "Distance.h"
using namespace cocos2d;
GeographicGateway* GeographicGateway::instance = NULL;
GeographicGateway::GeographicGateway(std::map<int, GeographicDataBaseTag*>* mapDataFormatMap) {
    this->size = new GeographicSize();
    this->slope = new GeographicSlope();
    Vec3 padding = Vec3(1280.0f * 0.425f, 1024 * 0.425f, 0.0f);
    int geographicId = 1;
    int worldAddressX = this->size->worldAddress.x;
    int worldAddressY = this->size->worldAddress.y;
    int worldAddressZ = this->size->worldAddress.z;
    for (int waz = 0; waz < worldAddressZ; waz++) {
        for (int way = 0; way < worldAddressY; way++) {
            for (int wax = 0; wax < worldAddressX; wax++) {
                int xidx = wax;
                int yidx = worldAddressY - (way + 1);
                int zidx = waz;
                int depth = GeographicDepth::create(worldAddressX - xidx, way + 1, waz + 1, 100, 100);
                float uw = this->size->unitSize.width + this->size->unitSpaceSize.width;
                float uh = this->size->unitSize.height + this->size->unitSpaceSize.height;
                float rsx = way * uw * this->slope->row.trigonomic.x;
                float rsy = way * uw * this->slope->row.trigonomic.y;
                float csx = wax * uw * this->slope->column.trigonomic.x;
                float csy = wax * uw * this->slope->column.trigonomic.y;
                float z = waz * uh;
                float x = rsx + csx - padding.x;
                float y = rsy + csy + padding.y + z;
                GeographicNode* node = new GeographicNode();
                node->depth = depth;
                node->geographicId = geographicId;
                node->position = Vec2(x, y);
                node->address = Address(xidx, yidx, zidx);
                node->type = 0;
                if (NULL != mapDataFormatMap && mapDataFormatMap->find(node->geographicId) != mapDataFormatMap->end()) {
                    GeographicDataBaseTag* tag = mapDataFormatMap->at(node->geographicId);
                    short mapTipType = 0;
                    if (0x01 == tag->header->tagType) {
                        mapTipType = ((GeographicDataFieldTag*)tag)->mapTipType;
                    } else {
                        mapTipType = ((GeographicDataBarrierTag*)tag)->mapTipType;
                    }
                    node->type = mapTipType;
                    node->parentGeographicId = tag->header->parentGeographicId;
                    BaseOrnamentBehaviour* behaviour = BarrierBehaviourFactory::factoryMethod(mapTipType, node);
                    if (NULL != behaviour) {
                        BehaviourCollection* collection = BehaviourCollection::getInstance();
                        collection->add(behaviour);
                    }
                }
                this->nodeVector[zidx][yidx][xidx] = node;
                geographicId++;
            }
        }
    }
    if (NULL != mapDataFormatMap) {
        for (std::map<int, GeographicDataBaseTag*>::iterator it = mapDataFormatMap->begin(); it != mapDataFormatMap->end(); it++) {
            CC_SAFE_DELETE(it->second);
        }
    }
    return;
}
GeographicGateway::~GeographicGateway() {
    this->clear();
    CC_SAFE_DELETE(this->slope);
    CC_SAFE_DELETE(this->size);
}
GeographicGateway* GeographicGateway::getInstance(std::map<int, GeographicDataBaseTag*>* mapDataFormatMap) {
    if (NULL == GeographicGateway::instance) {
        GeographicGateway::instance = new GeographicGateway(mapDataFormatMap);
    }
    return GeographicGateway::instance;
}
void GeographicGateway::update() {
    Position padding = Screen::getCenterPosition();
    int worldAddressX = this->size->worldAddress.x;
    int worldAddressY = this->size->worldAddress.y;
    int worldAddressZ = this->size->worldAddress.z;
    for (int waz = 0; waz < worldAddressZ; waz++) {
        for (int way = 0; way < worldAddressY; way++) {
            for (int wax = 0; wax < worldAddressX; wax++) {
                int xidx = wax;
                int yidx = worldAddressY - (way + 1);
                int zidx = waz;
                int depth = GeographicDepth::create(worldAddressX - xidx, way + 1, waz + 1, 100, 100);
                float uw = this->size->unitSize.width + this->size->unitSpaceSize.width;
                float uh = this->size->unitSize.height + this->size->unitSpaceSize.height;
                float rsx = wax * uw * this->slope->row.trigonomic.x;
                float rsy = wax * uw * this->slope->row.trigonomic.y;
                float csx = way * uw * this->slope->column.trigonomic.x;
                float csy = way * uw * this->slope->column.trigonomic.y;
                float z = waz * uh;
                float x = rsx + csx - padding.x;
                float y = rsy + csy + padding.y + z;
                GeographicNode* node = this->nodeVector[zidx][yidx][xidx];
                node->depth = depth;
                node->position = Vec2(x, y);
            }
        }
    }
}
GeographicNode* GeographicGateway::findByGeographicId(short geographicId) {
    for (int wz = 0; wz < this->size->worldAddress.z; wz++) {
        for (int wy = 0; wy < this->size->worldAddress.y; wy++) {
            for (int wx = 0; wx < this->size->worldAddress.x; wx++) {
                GeographicNode* node = this->nodeVector[wz][wy][wx];
                if (node->geographicId == geographicId) {
                    return node;
                }
            }
        }
    }
    return NULL;
}
GeographicNode* GeographicGateway::findByAddress(Address* address) { return this->findByAddress(address->x, address->y, address->z); }
GeographicNode* GeographicGateway::findByAddress(int x, int y) { return this->findByAddress(x, y, 0); }
GeographicNode* GeographicGateway::findByAddress(int x, int y, int z) { return this->nodeVector[z][y][x]; }
GeographicNode* GeographicGateway::findByPosition(Vec2 position) { return this->findByPosition(position.x, position.y); }
GeographicNode* GeographicGateway::findByPosition(float x, float y) {
    for (int wz = 0; wz < this->size->worldAddress.z; wz++) {
        for (int wy = 0; wy < this->size->worldAddress.y; wy++) {
            for (int wx = 0; wx < this->size->worldAddress.x; wx++) {
                GeographicNode* node = this->nodeVector[wz][wy][wx];
                if (node->collider->isHit(x, y)) {
                    return node;
                }
            }
        }
    }
    return NULL;
}
std::vector<GeographicNode*> GeographicGateway::find2x2ByAddress(Address address) { return this->find2x2ByAddress(address.x, address.y); }
std::vector<GeographicNode*> GeographicGateway::find2x2ByAddress(int x, int y) { return this->findBarrierByAddress(x, y, 2, 2); }
std::vector<GeographicNode*> GeographicGateway::find3x3ByAddress(Address address) { return this->find3x3ByAddress(address.x, address.y); }
std::vector<GeographicNode*> GeographicGateway::find3x3ByAddress(int x, int y) { return this->findBarrierByAddress(x, y, 3, 3); }
std::vector<GeographicNode*> GeographicGateway::find4x4ByAddress(Address address) { return this->find4x4ByAddress(address.x, address.y); }
std::vector<GeographicNode*> GeographicGateway::find4x4ByAddress(int x, int y) { return this->findBarrierByAddress(x, y, 4, 4); }
std::vector<GeographicNode*> GeographicGateway::findBarrierByAddress(int x, int y, int width, int height) {
    std::vector<GeographicNode*> ret;
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            if (!(0 <= i && i < this->size->worldAddress.x && 0 <= j && j < this->size->worldAddress.y)) {
                std::vector<GeographicNode*> empty;
                return empty;
            }
            GeographicNode* node = this->findByAddress(i, j);
            ret.push_back(node);
        }
    }
    return ret;
}
GeographicSize* GeographicGateway::getSize() { return this->size; }
GeographicSlope* GeographicGateway::getSlope() { return this->slope; }
void GeographicGateway::clear() {
    for (int wz = 0; wz < this->size->worldAddress.z; wz++) {
        for (int wy = 0; wy < this->size->worldAddress.y; wy++) {
            for (int wx = 0; wx < this->size->worldAddress.x; wx++) {
                GeographicNode* gnode = this->nodeVector[wz][wy][wx];
                CC_SAFE_DELETE(gnode);
            }
        }
    }
}
void GeographicGateway::destroy() { CC_SAFE_DELETE(GeographicGateway::instance); }
bool GeographicGateway::isClean() {
    for (int wz = 0; wz < this->size->worldAddress.z; wz++) {
        for (int wy = 0; wy < this->size->worldAddress.y; wy++) {
            for (int wx = 0; wx < this->size->worldAddress.x; wx++) {
                GeographicNode* node = this->nodeVector[wz][wy][wx];
                if (node->type != 0x0000) {
                    return false;
                }
            }
        }
    }
    return true;
}
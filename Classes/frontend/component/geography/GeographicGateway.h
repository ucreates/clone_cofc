//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef Map_h
#define Map_h

#include <vector>
#include <map>
#include "GeographicNode.h"
#include "GeographicSlope.h"
#include "GeographicSize.h"
#include "GeographicDataBaseTag.h"
#include "RectCollider.h"
class GeographicGateway {
   public:
    ~GeographicGateway();
    static GeographicGateway* getInstance(std::map<int, GeographicDataBaseTag*>* mapDataFormatMap = NULL);
    GeographicNode* findByGeographicId(short geographicId);
    GeographicNode* findByAddress(Address* address);
    GeographicNode* findByAddress(int x, int y);
    GeographicNode* findByAddress(int x, int y, int z);
    GeographicNode* findByPosition(cocos2d::Vec2 position);
    GeographicNode* findByPosition(float x, float y);

    std::vector<GeographicNode*> find2x2ByAddress(Address address);
    std::vector<GeographicNode*> find2x2ByAddress(int x, int y);
    std::vector<GeographicNode*> find3x3ByAddress(Address address);
    std::vector<GeographicNode*> find3x3ByAddress(int x, int y);
    std::vector<GeographicNode*> find4x4ByAddress(Address address);
    std::vector<GeographicNode*> find4x4ByAddress(int x, int y);
    std::vector<GeographicNode*> findBarrierByAddress(int x, int y, int width, int height);

    GeographicSize* getSize();
    GeographicSlope* getSlope();
    void update();
    bool isClean();
    void clear();
    static void destroy();

   private:
    GeographicSize* size;
    GeographicSlope* slope;
    GeographicNode* nodeVector[GeographicSize::MAX_COORDINATE_Z][GeographicSize::MAX_COORDINATE_Y][GeographicSize::MAX_COORDINATE_X];
    GeographicGateway(std::map<int, GeographicDataBaseTag*>* mapDataFormatMap = NULL);
    static GeographicGateway* instance;
};

#endif

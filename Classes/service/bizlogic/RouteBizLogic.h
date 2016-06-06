//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef RouteBizLogic_h
#define RouteBizLogic_h
// stl
#include <vector>

// geographic
#include "GeographicNode.h"

// service
#include "BaseBizLogic.h"

class RouteBizLogic : public BaseBizLogic {
   public:
    RouteBizLogic();
    virtual ~RouteBizLogic();
    std::vector<GeographicNode*> getRouteCache(unsigned int startGeographicId, unsigned int goalGeographicId);
    bool addRouteCache(unsigned int startGeographicId, unsigned int goalGeographicId, std::vector<GeographicNode*>);
    bool removeRouteCache(unsigned int startGeographicId, unsigned int goalGeographicId);
    void clear() override;
};

#endif

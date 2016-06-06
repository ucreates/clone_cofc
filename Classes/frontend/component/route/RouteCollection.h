//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef RouteCollection_h
#define RouteCollection_h

#include <vector>
#include "GeographicNode.h"
#include "GeographicGateway.h"
#include "AddressRangeValidator.h"

class RouteCollection {
   public:
    RouteCollection();
    RouteCollection(int distance, std::vector<GeographicNode*> routePointVector);
    ~RouteCollection();
    std::vector<GeographicNode*> getNodeVector();
    void setNodeVector(std::vector<GeographicNode*> routePointVector);
    int getDistance();
    void setDistance(int distance);

   private:
    std::vector<GeographicNode*> nodeVector;
    int distance;
    AddressRangeValidator validator;
};
#endif
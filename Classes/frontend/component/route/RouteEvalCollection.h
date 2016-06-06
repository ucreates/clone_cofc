//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef RouteEvalCollection_h
#define RouteEvalCollection_h

// stl
#include <vector>

// geography
#include "GeographicNode.h"

class RouteEvalCollection {
   public:
    RouteEvalCollection();
    ~RouteEvalCollection();
    void save(GeographicNode* node);
    bool isEmpty();
    bool isEvaluatedNode(GeographicNode* evalNode);
    bool erase(GeographicNode* evalNode);
    void clear();
    void dump();
    std::vector<GeographicNode*>* getNodeVector();
    RouteEvalCollection* operator=(RouteEvalCollection* value);

   private:
    std::vector<GeographicNode*>* nodeVector;
};
#endif

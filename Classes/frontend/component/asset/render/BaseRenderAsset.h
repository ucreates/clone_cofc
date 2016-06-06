//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseRenderAsset_h
#define BaseRenderAsset_h

// stl
#include <string>

// asset
#include "BaseAsset.h"

// behaviour
#include "Transform.h"
#include "OrnamentProperty.h"

// geography
#include "GeographicNode.h"

class GeographicNode;

class BaseRenderAsset : public BaseAsset {
   public:
    BaseRenderAsset();
    virtual ~BaseRenderAsset();

    cocos2d::Node* getNode();
    virtual void transform(int zorder);
    virtual void transform(GeographicNode* node);
    virtual void transform(GeographicNode* node, int depth);
    virtual void transform(GeographicNode* node, OrnamentProperty* property, int depth);
    virtual void transform(cocos2d::Vec2 position);
    virtual void transform(cocos2d::Vec2 position, OrnamentProperty* property);
    virtual void transform(Position position);
    virtual void transform(Position position, OrnamentProperty* property);
    virtual void transform(float x, float y);
    virtual void transform(cocos2d::Size scale);
    virtual void transform(cocos2d::Size* scale);
    virtual void transform(float rotate);
    virtual void transform(GLubyte alpha);
    virtual void transform(float x, float y, int z);
    virtual void transform(float x, float y, int z, float width, float height, float rotate, GLubyte alpha, bool dump = false);
    virtual void transform(bool transform = true);
    virtual void addLayer(cocos2d::Layer* layer, int depth);
    virtual void show();
    virtual void hide();
    virtual Transform getTransform();

   protected:
    std::string relativePath;
    cocos2d::Node* node;
};

#endif

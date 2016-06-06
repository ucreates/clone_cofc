//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef BaseBehaviour_h
#define BaseBehaviour_h

// cocos2d
#include "cocos2d.h"

// frame
#include "TimeLine.h"

// geography
#include "GeographicNode.h"

// entity
#include "Transform.h"

// asset
#include "AssetCollection.h"
#include "BaseRenderAsset.h"

// behaviour
#include "BaseProperty.h"

// collider
#include "BaseCollider.h"

class BaseRenderAsset;
class AssetCollection;
class BaseCollider;
class GeographicNode;

class BaseBehaviour {
   public:
    BaseBehaviour();
    virtual ~BaseBehaviour();

    // event handler
    virtual void onCreate();
    virtual void onCreate(cocos2d::Layer* layer);
    virtual void onCreate(cocos2d::Layer* layer, int depth);
    virtual void onCreate(cocos2d::Layer* layer, Position position);
    virtual void onCreate(cocos2d::Layer* layer, Position position, cocos2d::Size scale);
    virtual void onUpdate(float time = 0.0f);
    virtual void onCollision();

    // getter
    BaseAsset* getAsset(std::string assetName);
    BaseProperty* getProperty();
    cocos2d::Layer* getLayer();
    GeographicNode* getGeographicNode();

    // setter
    void setGeographicNode(GeographicNode* node);

   protected:
    GeographicNode* geographicNode;
    AssetCollection* asset;
    BaseProperty* property;
    cocos2d::Layer* layer;
    BaseCollider* collider;
};
#endif

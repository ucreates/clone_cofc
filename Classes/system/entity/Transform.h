//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Transform_h
#define Transform_h
// cocos2d
#include "cocos2d.h"
// entity
#include "Position.h"
#include "Scale.h"
class Transform {
   public:
    Transform();
    Transform(cocos2d::Vec2 position, int zorder, cocos2d::Size scale, cocos2d::Size contentSize, float rotate, GLubyte alpha);
    ~Transform();
    void update(cocos2d::Vec2 position, int zorder, cocos2d::Size scale, float rotate, GLubyte alpha);
    void update(cocos2d::Vec2 position, int zorder, cocos2d::Size scale, cocos2d::Size contentSize, float rotate, GLubyte alpha);
    Position getPosition();
    cocos2d::Size getScale();
    float getRotate();
    GLubyte getAlpha();
    Scale getContentsScale();
    Transform* operator=(Transform& entity);
   private:
    Position position;
    cocos2d::Size scale;
    Scale contentSize;
    float rotate;
    GLubyte alpha;
};
#endif

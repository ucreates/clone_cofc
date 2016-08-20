//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// math
#include "Radian.h"
float Radian::create(cocos2d::Vec2 start, cocos2d::Vec2 goal) {
    float x = goal.x - start.x;
    float y = goal.y - start.y;
    float radian = atan2(y, x);
    return radian;
}
float Radian::create(Position start, Position goal) { return Radian::create(start.vector2d, goal.vector2d); }
float Radian::create(Transform* transform, GeographicNode* node) {
    Position pos = transform->getPosition();
    return Radian::create(node->position, pos.vector2d);
}

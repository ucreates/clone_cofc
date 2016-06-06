//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "Move.h"
#include "Radian.h"
#include "Position.h"

using namespace cocos2d;

Position Move::execute(Position start, Position goal, float speed) {
    float radian = Radian::create(start.vector2d, goal.vector2d);
    float sin = sinf(radian);
    float cos = cosf(radian);
    float dx = speed * cos;
    float dy = speed * sin;

    start.add(Vec2(dx, dy));
    return start;
}

Vec2 Move::execute(Vec2 start, Vec2 goal, float speed) {
    float radian = Radian::create(start, goal);
    float sin = sinf(radian);
    float cos = cosf(radian);
    float dx = speed * cos;
    float dy = speed * sin;

    return Vec2(start.x + dx, start.y + dy);
}

Vec2 Move::execute(Vec2 position, float degree, float speed) {
    float radian = CC_DEGREES_TO_RADIANS(degree);
    float sin = sinf(radian);
    float cos = cosf(radian);
    float dx = speed * cos;
    float dy = speed * sin;

    float x = position.x + dx;
    float y = position.y + dy;
    return Vec2(x, y);
}

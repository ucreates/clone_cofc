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
#include "Coordinate.h"
using namespace cocos2d;
Vec2 Coordinate::getMiddlePoint(Vec2 start, Vec2 goal) {
    int x = start.x + goal.x;
    int y = start.y + goal.y;
    return Vec2(x * 0.5f, y * 0.5f);
}
Position Coordinate::getMiddlePoint(Position start, Position goal) {
    float x = start.x + goal.x;
    float y = start.y + goal.y;
    int z = start.zorder + goal.zorder;
    return Position(Vec2(x * 0.5f, y * 0.5f), z);
}
Address Coordinate::getMiddlePoint(Address start, Address goal) {
    int x = start.x + goal.x;
    int y = start.y + goal.y;
    return Address(x / 2, y / 2);
}
Vec2 Coordinate::getBetweenPoint(Vec2 start, Vec2 goal, float percentage) {
    if (percentage > 1.0f) {
        return Vec2::ZERO;
    }
    float m = percentage;
    float n = 1.0f - percentage;
    int x = start.x * n + goal.x * m;
    int y = start.y * n + goal.y * m;
    return Vec2(x, y);
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// standard
#include <stdlib.h>
// math
#include "Distance.h"
using namespace cocos2d;
float Distance::create(Position start, Position goal) {
    float x = start.x - goal.x;
    float y = start.y - goal.y;
    float z = (float)start.zorder - (float)goal.zorder;
    float distance = powf(fabsf(x), 2) + powf(fabsf(y), 2) + powf(fabsf(z), 2);
    return sqrt(distance);
}
float Distance::create(Vec2 start, Vec2 goal) {
    float x = start.x - goal.x;
    float y = start.y - goal.y;
    float distance = powf(fabsf(x), 2.0f) + powf(fabsf(y), 2.0f);
    distance = sqrt(distance);
    return distance;
}
int Distance::create(Address start, Address goal) {
    int x = goal.x - start.x;
    int y = goal.y - start.y;
    int distance = pow(abs(x), 2) + pow(abs(y), 2);
    return (int)sqrt(distance);
}
float Distance::create(Size screenSize) {
    float distance = powf(fabsf(screenSize.width), 2) + powf(fabsf(screenSize.height), 2);
    distance = sqrt(distance);
    return distance;
}
float Distance::create(Transform* transform, GeographicNode* node) {
    Position pos = transform->getPosition();
    float x = node->position.x - pos.x;
    float y = node->position.y - pos.y;
    float distance = powf(fabsf(x), 2) + powf(fabsf(y), 2);
    return sqrt(distance);
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// entity
#include "Transform.h"
// vfx
#include "Alpha.h"
using namespace cocos2d;
Transform::Transform() {
    this->rotate = 0;
    this->alpha = Alpha::NOT_ALPHA;
}
Transform::Transform(Vec2 position, int zorder, Size scale, Size contentSize, float rotate, GLubyte alpha)
    : scale(Size(scale.width, scale.height)), contentSize(Scale(contentSize)), position(Position(position, zorder)), rotate(rotate), alpha(Alpha::NOT_ALPHA) {
    this->update(position, zorder, scale, contentSize, rotate, alpha);
}
Transform::~Transform() {}
void Transform::update(cocos2d::Vec2 position, int zorder, Size scale, float rotate, GLubyte alpha) {
    this->position = Position(position, zorder);
    this->scale.width = scale.width;
    this->scale.height = scale.height;
    this->rotate = rotate;
    this->alpha = alpha;
}
void Transform::update(Vec2 position, int zorder, Size scale, Size contentSize, float rotate, GLubyte alpha) {
    this->contentSize.update(contentSize);
    this->update(position, zorder, scale, rotate, alpha);
}
Position Transform::getPosition() { return this->position; }
Size Transform::getScale() { return this->scale; }
float Transform::getRotate() { return this->rotate; }
GLubyte Transform::getAlpha() { return this->alpha; }
Scale Transform::getContentsScale() { return this->contentSize; }
Transform* Transform::operator=(Transform& entity) {
    this->position = entity.getPosition();
    this->scale = entity.getScale();
    this->contentSize = entity.getContentsScale();
    this->rotate = entity.getRotate();
    this->alpha = entity.getAlpha();
    return this;
}

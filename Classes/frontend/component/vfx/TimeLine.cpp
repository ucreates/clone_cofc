//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "TimeLine.h"

TimeLine::TimeLine() { this->reset(); }

int TimeLine::getFrame() { return this->frame; }

void TimeLine::setFrame(int frame) { this->frame += frame; }

float TimeLine::getFrameTime() { return this->frameTime; }

void TimeLine::setFrameTime(float delta) { this->frameTime += delta; }

void TimeLine::update(float delta, int frame) {
    this->setFrameTime(delta);
    this->setFrame(frame);
}

void TimeLine::reset() {
    this->frameTime = 0.0f;
    this->frame = 0;
}

void TimeLine::reset(int frame, float frameTime) {
    this->frameTime = frameTime;
    this->frame = frame;
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// timer
#include "SceneTimer.h"
// utility
#include "ConvertUtility.h"
SceneTimer::SceneTimer(int totalTime) { this->totalTime = totalTime; }
SceneTimer::~SceneTimer() {}
float SceneTimer::getTime() { return this->totalTime; }
std::string SceneTimer::getTimeString() {
    int minite = this->totalTime / 60;
    int second = this->totalTime % 60;
    return "TIME : " + ConvertUtility::toString(minite) + "m" + ConvertUtility::toString(second) + "s";
}
void SceneTimer::update(float delta) {
    if (1.0f <= this->deltaTime) {
        this->totalTime -= 1;
        if (0.0f >= this->totalTime) {
            this->totalTime = 0;
        }
        this->deltaTime = 0.0f;
    }
    this->deltaTime += delta;
}
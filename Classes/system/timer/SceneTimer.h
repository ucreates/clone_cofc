//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef SceneTimer_h
#define SceneTimer_h
// stl
#include <string>
class SceneTimer {
   public:
    SceneTimer(int totalTime);
    ~SceneTimer();
    float getTime();
    std::string getTimeString();
    void update(float delta);
   private:
    int totalTime;
    float deltaTime;
};
#endif

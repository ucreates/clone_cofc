//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef PerformanceTimer_h
#define PerformanceTimer_h

// stl
#include <vector>
#include <string>

class PerformanceTimer {
   public:
    PerformanceTimer();
    void start();
    void stop();
    float getResultTimeSecond();
    float getResultTimeMilliSecond();
    float getAverageSecond();
    float getAverageMilliSecond();
    std::string getAverageTimeString();
    void clear();

   private:
    float statTime;
    float endTime;
    std::vector<float> secondTimeVector;
    std::vector<float> milliSecondTimeVector;
};

#endif

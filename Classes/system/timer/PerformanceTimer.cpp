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
#include <time.h>

// timer
#include "PerformanceTimer.h"

// utility
#include "ConvertUtility.h"

PerformanceTimer::PerformanceTimer() {}

void PerformanceTimer::start() { this->statTime = (float)clock(); }

void PerformanceTimer::stop() {
    this->endTime = (float)clock();
    float second = this->getResultTimeSecond();
    this->secondTimeVector.push_back(second);

    float millisecond = this->getResultTimeMilliSecond();
    this->milliSecondTimeVector.push_back(millisecond);
}

float PerformanceTimer::getResultTimeSecond() {
    float result = (this->endTime - this->statTime) / 1000000.0f;
    return result;
}

float PerformanceTimer::getResultTimeMilliSecond() {
    float result = this->getResultTimeSecond() * 1000.0f;
    return result;
}

float PerformanceTimer::getAverageSecond() {
    float result = 0;
    for (std::vector<float>::iterator it = this->secondTimeVector.begin(); it != this->secondTimeVector.end(); it++) {
        result += (float)(*it);
    }
    result /= this->secondTimeVector.size();
    return result;
}

float PerformanceTimer::getAverageMilliSecond() {
    float result = 0;
    for (std::vector<float>::iterator it = this->milliSecondTimeVector.begin(); it != this->milliSecondTimeVector.end(); it++) {
        result += (float)(*it);
    }
    result /= this->milliSecondTimeVector.size();
    return result;
}

std::string PerformanceTimer::getAverageTimeString() {
    float second = this->getAverageSecond();
    float millisecond = this->getAverageMilliSecond();
    return ConvertUtility::toString(second) + "sec. (" + ConvertUtility::toString(millisecond) + "milli sec.)";
}

void PerformanceTimer::clear() {
    this->secondTimeVector.clear();
    this->milliSecondTimeVector.clear();
}

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// debug
#include "Macro.h"
// device
#include "Screen.h"
using namespace cocos2d;
Size Screen::getFullScreenSize(float scale) {
    if (0.0f == scale) {
        return Size::ZERO;
    }
    Director* director = Director::getInstance();
    Size windowSize = director->getWinSize();
    windowSize.width *= scale;
    windowSize.height *= scale;
    return windowSize;
}
Size Screen::getHalfScreenSize(float scale) {
    Size windowSize = Screen::getFullScreenSize(scale);
    return Size(windowSize.width * 0.5f, windowSize.height * 0.5f);
}
Position Screen::getCenterPosition(int zorder) {
    Director* director = Director::getInstance();
    Size windowSize = director->getWinSize();
    return Position(Vec2(windowSize.width * 0.5f, windowSize.height * 0.5f), zorder);
}
Position Screen::getEdgePosition(int zorder) {
    Director* director = Director::getInstance();
    Size windowSize = director->getWinSize();
    return Position(Vec2(windowSize.width, windowSize.height), zorder);
}
Size Screen::getNodeScaleByScreenSize(Node* node, bool dump) {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    float wr = node->getContentSize().width / visibleSize.width;
    float hr = node->getContentSize().height / visibleSize.height;
    if (false != dump) {
        CCLOG("横幅比率%f", wr);
        CCLOG("横幅%f", 1.0f / wr);
        CCLOG("縦幅比率%f", hr);
        CCLOG("縦幅%f", 1.0f / hr);
    }
    return Size(1.0f / wr, 1.0f / hr);
}

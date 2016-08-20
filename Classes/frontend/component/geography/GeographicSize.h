//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicSize_h
#define GeographicSize_h
#include "cocos2d.h"
#include "Address.h"
class GeographicSize {
   public:
    static const int MAX_COORDINATE_X = 38;
    static const int MAX_COORDINATE_Y = 38;
    static const int MAX_COORDINATE_Z = 1;
    //アドレス
    Address worldAddress;
    // node数(x, y)
    cocos2d::Size worldSize;
    //マップ(1ユニット単位)サイズ
    // w*h:56*42
    // 1辺の長さ:35px
    cocos2d::Size unitSize;
    //ユニットの半分のサイズ
    cocos2d::Size unitHalfSize;
    //ユニット間のスペースサイズ
    cocos2d::Size unitSpaceSize;
    GeographicSize();
    GeographicSize(Address worldAddress, cocos2d::Size unitSize, cocos2d::Size unitSpaceSize);
};
#endif

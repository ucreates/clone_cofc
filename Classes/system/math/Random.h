//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Random_h
#define Random_h
class Random {
   public:
    static int create(int number, bool forArray = false);
    static int create(int min, int max, bool forArray = false);
};
#endif
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BaseFieldSchema_h
#define BaseFieldSchema_h
class BaseFieldSchema {
   public:
    BaseFieldSchema();
    virtual ~BaseFieldSchema();
    virtual bool equal(BaseFieldSchema* field);
    virtual bool moreThan(BaseFieldSchema* field);
    virtual bool moreThanEqual(BaseFieldSchema* field);
    virtual bool lessThan(BaseFieldSchema* field);
    virtual bool lessThanEqual(BaseFieldSchema* field);
};
#endif

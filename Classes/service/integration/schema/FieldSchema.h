//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef FieldSchema_h
#define FieldSchema_h

// service
#include "BaseFieldSchema.h"

template <typename T>
class FieldSchema : public BaseFieldSchema {
   public:
    FieldSchema();
    FieldSchema(T value);
    virtual ~FieldSchema();
    T getValue();
    void setValue(T value);
    bool equal(BaseFieldSchema* field) override;
    bool moreThan(BaseFieldSchema* field) override;
    bool moreThanEqual(BaseFieldSchema* field) override;
    bool lessThan(BaseFieldSchema* field) override;
    bool lessThanEqual(BaseFieldSchema* field) override;

   private:
    T value;
};

#endif

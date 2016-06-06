//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef UnitOfWork_h
#define UnitOfWork_h

// stl
#include <vector>

// service
#include "Dao.h"

template <class T>
class UnitOfWork {
   public:
    UnitOfWork();
    ~UnitOfWork();
    bool add();
    bool update();
    bool remove();
    bool commit();
    bool rollback();
    void clear();
    bool registerAddRecord(T record);
    bool registerUpdateRecord(T record);
    bool registerRemoveRecord(T record);

   private:
    std::vector<T> addRecordVector;
    std::vector<T> updateRecordVector;
    std::vector<T> removeRecordVector;
    std::vector<T> preUpdateRecordVector;
    std::vector<T> postAddRecordVector;
    int rollbackId;
    bool enableRegister(std::vector<T> recordVector, T record);
};

#endif

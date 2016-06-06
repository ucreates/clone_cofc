//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef DataBase_h
#define DataBase_h

// stl
#include <map>

// service
#include "BaseDao.h"
#include "Dao.h"

class DataBase {
   public:
    ~DataBase();
    static DataBase* getInstance();
    template <typename T>
    Dao<T>* findBy();
    template <typename T>
    bool add(Dao<T>* dao);
    void clear();
    static void destroy();

   private:
    static DataBase* instance;
    std::map<std::string, BaseDao*> daoMap;
    DataBase();
};

#endif
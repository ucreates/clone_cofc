//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef Dao_h
#define Dao_h
// stl
#include <vector>
// service
#include "BaseDao.h"
#include "BaseExpression.h"
#include "ConditionExpression.h"
#include "KeySchema.h"
#include "LimitExpression.h"
#include "MultiConditionExpression.h"
#include "OrderByExpression.h"
template <class T>
class Dao : public BaseDao {
   public:
    Dao();
    virtual ~Dao();
    // find
    T findBy(int id);
    T findBy(int id, int& index);
    T findBy(KeySchema primaryKey);
    T findBy(KeySchema primaryKey, int& index);
    std::vector<T> findBy(BaseExpression* expression, BaseExpression* order = NULL, BaseExpression* limit = NULL);
    std::vector<T> findAll(BaseExpression* expression = NULL);
    T findFirst();
    T findLast();
    T findPrevious();
    T findNext();
    // save
    bool save();
    bool save(T record);
    // update
    bool update(int id, T record);
    bool update(T record);
    // remove
    bool remove(int id);
    bool remove(T record);
    // sort
    std::vector<T> orderBy(std::string orderFieldSchemaName, std::vector<T> recordVector, OrderByExpression::OrderType orderType);
    // getter
    int count();
    int getId();
    // default
    void clear() override;
    void reset() override;
    void reset(int rollbackId);
    // status
    bool isEor();
    bool isFor();
   private:
    int id;
    int seek;
    std::vector<T> recordVector;
};
#endif
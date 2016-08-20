//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// service
#include "Dao.h"
#include "BaseTable.h"
#include "TDownLoadTable.h"
#include "TLayerTable.h"
#include "TOverAllTable.h"
#include "TBarrierTable.h"
#include "TUnitTable.h"
#include "TResourceTable.h"
#include "TRouteTable.h"
#include "TAssetTable.h"
#include "MUnitTable.h"
#include "MBarrierTable.h"
#include "MResourceTable.h"
using namespace std;
template <typename T>
Dao<T>::Dao() {
    this->id = 0;
}
template <typename T>
Dao<T>::~Dao() {
    this->recordVector.clear();
}
template <typename T>
T Dao<T>::findBy(int id) {
    int index;
    return this->findBy(id, index);
}
template <typename T>
T Dao<T>::findBy(int id, int& index) {
    int left = 0;
    int right = this->count() - 1;
    T ret;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        T record = this->recordVector.at(mid);
        if (id < record.id) {
            right = mid - 1;
        } else if (id > record.id) {
            left = mid + 1;
        } else {
            index = mid;
            ret = record;
            break;
        }
    }
    return ret;
}
template <typename T>
T Dao<T>::findBy(KeySchema primaryKey) {
    int index;
    return this->findBy(primaryKey, index);
}
template <typename T>
T Dao<T>::findBy(KeySchema primaryKey, int& index) {
    T record;
    if (this->recordVector.empty()) {
        return record;
    }
    int id = primaryKey.getId();
    record = this->findBy(id, index);
    if (0 != record.id && record.primaryKey == primaryKey) {
        return record;
    }
    return record;
}
template <typename T>
vector<T> Dao<T>::findBy(BaseExpression* expression, BaseExpression* order, BaseExpression* limit) {
    vector<T> ret;
    if (this->recordVector.empty()) {
        return ret;
    }
    std::vector<ConditionExpression> conditionVector;
    if ("and" == expression->getExpressionType() || "or" == expression->getExpressionType()) {
        MultiConditionExpression* mcexp = (MultiConditionExpression*)expression;
        conditionVector = mcexp->getConditionExpression();
    } else {
        ConditionExpression cexp = *(ConditionExpression*)expression;
        conditionVector.push_back(cexp);
    }
    for (typename std::vector<T>::iterator it = this->recordVector.begin(); it != this->recordVector.end(); it++) {
        T record = *it;
        bool add = false;
        for (std::vector<ConditionExpression>::iterator ct = conditionVector.begin(); ct != conditionVector.end(); ct++) {
            ConditionExpression condition = *ct;
            BaseTable baseRecord = (BaseTable)record;
            BaseFieldSchema* field = baseRecord.compareFieldIterator.get(condition.fieldName);
            if (NULL == field) {
                break;
            }
            if (condition.comparisonOperator == "==") {
                add = field->equal(condition.field);
            } else if (condition.comparisonOperator == ">") {
                add = field->moreThan(condition.field);
            } else if (condition.comparisonOperator == ">=") {
                add = field->moreThanEqual(condition.field);
            } else if (condition.comparisonOperator == "<") {
                add = field->lessThan(condition.field);
            } else if (condition.comparisonOperator == "<=") {
                add = field->lessThanEqual(condition.field);
            }
            if ("and" == expression->getExpressionType() && false == add) {
                break;
            } else if ("or" == expression->getExpressionType() && false != add) {
                break;
            }
        }
        if (false != add) {
            ret.push_back(record);
        }
    }
    if (1 < ret.size() && order != NULL && "orderby" == order->getExpressionType()) {
        OrderByExpression* obexp = (OrderByExpression*)order;
        std::string fieldName = obexp->getOrderFieldSchemaName();
        OrderByExpression::OrderType orderType = obexp->getOrderType();
        ret = this->orderBy(fieldName, ret, orderType);
    }
    if (1 < ret.size() && limit != NULL && "limit" == limit->getExpressionType()) {
        LimitExpression* exp = (LimitExpression*)limit;
        long limit = exp->getLimit();
        if (limit < this->recordVector.size()) {
            std::vector<T> tmp;
            for (long i = 0; i < limit; i++) {
                T record = ret[i];
                tmp.push_back(record);
            }
            ret = tmp;
        }
    }
    return ret;
}
template <typename T>
std::vector<T> Dao<T>::findAll(BaseExpression* expression) {
    if (NULL == expression) {
        return this->recordVector;
    }
    std::vector<T> ret;
    if ("orderby" == expression->getExpressionType()) {
        OrderByExpression* obexp = (OrderByExpression*)expression;
        std::string fieldName = obexp->getOrderFieldSchemaName();
        OrderByExpression::OrderType orderType = obexp->getOrderType();
        ret = this->orderBy(fieldName, this->recordVector, orderType);
    } else if ("limit" == expression->getExpressionType()) {
        LimitExpression* exp = (LimitExpression*)expression;
        long limit = exp->getLimit();
        if (limit < this->recordVector.size()) {
            std::vector<T> tmp;
            for (long i = 0; i < limit; i++) {
                T record = this->recordVector[i];
                tmp.push_back(record);
            }
            ret = tmp;
        }
    }
    return ret;
}
template <typename T>
T Dao<T>::findFirst() {
    return this->recordVector.at(0);
}
template <typename T>
T Dao<T>::findNext() {
    if (this->seek < this->count() - 1) {
        this->seek++;
    }
    return this->recordVector.at(this->seek);
}
template <typename T>
T Dao<T>::findPrevious() {
    if (this->seek > 0) {
        this->seek--;
    }
    return this->recordVector.at(this->seek);
}
template <typename T>
T Dao<T>::findLast() {
    int index = this->count() - 1;
    return this->recordVector.at(index);
}
template <typename T>
bool Dao<T>::save() {
    if (0 == this->count()) {
        T record;
        return this->save(record);
    }
    return false;
}
template <typename T>
bool Dao<T>::save(T record) {
    T t = this->findBy(record.primaryKey);
    if (0 != t.id) {
        return false;
    }
    this->id++;
    record.id = this->id;
    record.build();
    this->recordVector.push_back(record);
    return true;
}
template <typename T>
bool Dao<T>::update(int id, T record) {
    int index;
    T r = this->findBy(id, index);
    if (0 != r.id) {
        this->recordVector[index] = record;
        return true;
    }
    return false;
}
template <typename T>
bool Dao<T>::update(T record) {
    int index;
    T r = this->findBy(record.primaryKey, index);
    if (0 != r.id) {
        this->recordVector[index] = record;
        return true;
    }
    return false;
}
template <typename T>
bool Dao<T>::remove(int id) {
    int index;
    T r = this->findBy(id, index);
    if (0 != r.id) {
        r.clear();
        this->recordVector.erase(this->recordVector.begin() + index);
        return true;
    }
    return false;
}
template <typename T>
bool Dao<T>::remove(T record) {
    int index;
    T r = this->findBy(record.primaryKey, index);
    if (0 != r.id) {
        r.clear();
        this->recordVector.erase(this->recordVector.begin() + index);
        return true;
    }
    return false;
}
template <typename T>
std::vector<T> Dao<T>::orderBy(std::string orderFieldSchemaName, std::vector<T> recordVector, OrderByExpression::OrderType orderType) {
    std::vector<T> ret;
    copy(recordVector.begin(), recordVector.end(), back_inserter(ret));
    for (long i = 0; i < ret.size() - 1; i++) {
        for (long j = ret.size() - 1; j > i; j--) {
            BaseTable recordA = ret[j];
            BaseTable recordB = ret[j - 1];
            BaseFieldSchema* fieldA = recordA.compareFieldIterator.get(orderFieldSchemaName);
            BaseFieldSchema* fieldB = recordB.compareFieldIterator.get(orderFieldSchemaName);
            if ((OrderByExpression::OrderType::Asc == orderType && fieldA->lessThan(fieldB)) || (OrderByExpression::OrderType::Desc == orderType && fieldA->moreThan(fieldB))) {
                T record = ret[j];
                ret[j] = ret[j - 1];
                ret[j - 1] = record;
            }
        }
    }
    return ret;
}
template <typename T>
int Dao<T>::count() {
    return (int)this->recordVector.size();
}
template <typename T>
void Dao<T>::clear() {
    this->id = 0;
    this->seek = 0;
    for (typename std::vector<T>::iterator it = this->recordVector.begin(); it != this->recordVector.end(); it++) {
        BaseTable record = (BaseTable)(*it);
        record.clear();
    }
    this->recordVector.clear();
    return;
}
template <typename T>
void Dao<T>::reset() {
    this->seek = 0;
    return;
}
template <typename T>
void Dao<T>::reset(int rollbackId) {
    this->id = rollbackId;
}
template <typename T>
int Dao<T>::getId() {
    return this->id;
}
template <typename T>
bool Dao<T>::isFor() {
    return (this->seek == 0);
}
template <typename T>
bool Dao<T>::isEor() {
    return (this->seek == this->count() - 1);
}
template class Dao<BaseTable>;
// master
template class Dao<MUnitTable>;
template class Dao<MBarrierTable>;
template class Dao<MResourceTable>;
// transaction
template class Dao<TDownLoadTable>;
template class Dao<TLayerTable>;
template class Dao<TOverAllTable>;
template class Dao<TBarrierTable>;
template class Dao<TUnitTable>;
template class Dao<TResourceTable>;
template class Dao<TRouteTable>;
template class Dao<TAssetTable>;
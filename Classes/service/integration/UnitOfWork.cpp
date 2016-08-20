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
#include "UnitOfWork.h"
#include "DataBase.h"
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
template <class T>
UnitOfWork<T>::UnitOfWork() {}
template <class T>
UnitOfWork<T>::~UnitOfWork() {}
template <class T>
bool UnitOfWork<T>::add() {
    DataBase* db = DataBase::getInstance();
    Dao<T>* dao = db->findBy<T>();
    for (int i = 0; i < this->addRecordVector.size(); i++) {
        T record = this->addRecordVector.at(i);
        bool ret = dao->save(record);
        if (false == ret) {
            return false;
        }
        int id = dao->getId();
        T savedRecord = dao->findBy(id);
        this->postAddRecordVector.push_back(savedRecord);
    }
    return true;
}
template <class T>
bool UnitOfWork<T>::update() {
    DataBase* db = DataBase::getInstance();
    Dao<T>* dao = db->findBy<T>();
    for (int i = 0; i < this->updateRecordVector.size(); i++) {
        T record = this->updateRecordVector.at(i);
        T old = dao->findBy(record.primaryKey);
        this->preUpdateRecordVector.push_back(old);
        bool ret = dao->update(record);
        if (false == ret) {
            return false;
        }
    }
    return true;
}
template <class T>
bool UnitOfWork<T>::remove() {
    DataBase* db = DataBase::getInstance();
    Dao<T>* dao = db->findBy<T>();
    for (int i = 0; i < this->removeRecordVector.size(); i++) {
        T record = this->removeRecordVector.at(i);
        bool ret = dao->remove(record);
        if (false == ret) {
            return false;
        }
    }
    return true;
}
template <class T>
bool UnitOfWork<T>::commit() {
    DataBase* db = DataBase::getInstance();
    Dao<T>* dao = db->findBy<T>();
    this->rollbackId = dao->getId() - (int)this->addRecordVector.size();
    bool ret = this->remove();
    if (false == ret) {
        return false;
    }
    ret = this->update();
    if (false == ret) {
        return false;
    }
    ret = this->add();
    if (false == ret) {
        return false;
    }
    return true;
}
template <class T>
bool UnitOfWork<T>::rollback() {
    DataBase* db = DataBase::getInstance();
    Dao<T>* dao = db->findBy<T>();
    for (int i = 0; i < this->postAddRecordVector.size(); i++) {
        T record = this->postAddRecordVector.at(i);
        bool ret = dao->remove(record);
        if (false == ret) {
            return false;
        }
    }
    for (int i = 0; i < this->preUpdateRecordVector.size(); i++) {
        T record = this->preUpdateRecordVector.at(i);
        bool ret = dao->update(record);
        if (false == ret) {
            return false;
        }
    }
    dao->reset(this->rollbackId);
    for (int i = 0; i < this->removeRecordVector.size(); i++) {
        T record = this->removeRecordVector.at(i);
        bool ret = dao->save(record);
        if (false == ret) {
            return false;
        }
    }
    return true;
}
template <class T>
void UnitOfWork<T>::clear() {
    this->addRecordVector.clear();
    this->updateRecordVector.clear();
    this->removeRecordVector.clear();
    this->preUpdateRecordVector.clear();
    this->postAddRecordVector.clear();
}
template <class T>
bool UnitOfWork<T>::registerAddRecord(T record) {
    if (0 != record.id) {
        return false;
    }
    this->addRecordVector.push_back(record);
    return true;
}
template <class T>
bool UnitOfWork<T>::registerUpdateRecord(T record) {
    if (!this->enableRegister(this->removeRecordVector, record)) {
        return false;
    }
    if (!this->enableRegister(this->updateRecordVector, record)) {
        return false;
    }
    this->updateRecordVector.push_back(record);
    return true;
}
template <class T>
bool UnitOfWork<T>::registerRemoveRecord(T record) {
    if (!this->enableRegister(this->removeRecordVector, record)) {
        return false;
    }
    if (!this->enableRegister(this->updateRecordVector, record)) {
        return false;
    }
    this->removeRecordVector.push_back(record);
    return true;
}
template <class T>
bool UnitOfWork<T>::enableRegister(std::vector<T> recordVector, T record) {
    if (0 == record.id) {
        return false;
    }
    int left = 0;
    int right = (int)recordVector.size() - 1;
    T ret;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        T registeredRecord = recordVector.at(mid);
        if (record.id < registeredRecord.id) {
            right = mid - 1;
        } else if (record.id > registeredRecord.id) {
            left = mid + 1;
        } else {
            return false;
        }
    }
    return true;
}
// unit of work
template class UnitOfWork<BaseTable>;
template class UnitOfWork<TLayerTable>;
template class UnitOfWork<TOverAllTable>;
template class UnitOfWork<TBarrierTable>;
template class UnitOfWork<TUnitTable>;
template class UnitOfWork<TResourceTable>;
template class UnitOfWork<TRouteTable>;
template class UnitOfWork<TAssetTable>;
template class UnitOfWork<MUnitTable>;
template class UnitOfWork<MBarrierTable>;
template class UnitOfWork<MResourceTable>;
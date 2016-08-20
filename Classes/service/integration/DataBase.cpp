//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// standard
#include <cxxabi.h>
// entity
#include "Value.h"
// service
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
DataBase* DataBase::instance = NULL;
DataBase::DataBase() {
    this->add<TLayerTable>(new Dao<TLayerTable>());
    this->add<TDownLoadTable>(new Dao<TDownLoadTable>());
    this->add<TOverAllTable>(new Dao<TOverAllTable>());
    this->add<TBarrierTable>(new Dao<TBarrierTable>());
    this->add<TUnitTable>(new Dao<TUnitTable>());
    this->add<TResourceTable>(new Dao<TResourceTable>());
    this->add<TRouteTable>(new Dao<TRouteTable>());
    this->add<TAssetTable>(new Dao<TAssetTable>());
    this->add<MUnitTable>(new Dao<MUnitTable>());
    this->add<MBarrierTable>(new Dao<MBarrierTable>());
    this->add<MResourceTable>(new Dao<MResourceTable>());
}
DataBase::~DataBase() {
    for (std::map<std::string, BaseDao*>::iterator it = this->daoMap.begin(); it != this->daoMap.end(); ++it) {
        it->second->clear();
        CC_SAFE_DELETE(it->second);
    }
}
DataBase* DataBase::getInstance() {
    if (NULL == DataBase::instance) {
        DataBase::instance = new DataBase();
    }
    return DataBase::instance;
}
template <typename T>
bool DataBase::add(Dao<T>* dao) {
    T t;
    int stat;
    Dao<T>* existDao = this->findBy<T>();
    if (NULL != existDao) {
        return false;
    }
    char* daoName = abi::__cxa_demangle(typeid(t).name(), 0, 0, &stat);
    this->daoMap.insert(std::map<std::string, BaseDao*>::value_type(daoName, dao));
    std::free(daoName);
    return true;
}
template <typename T>
Dao<T>* DataBase::findBy() {
    T t;
    int stat;
    char* daoName = abi::__cxa_demangle(typeid(t).name(), 0, 0, &stat);
    if (this->daoMap.end() == this->daoMap.find(daoName)) {
        std::free(daoName);
        return NULL;
    }
    Dao<T>* dao = (Dao<T>*)this->daoMap[daoName];
    dao->reset();
    std::free(daoName);
    return dao;
}
void DataBase::clear() {
    for (std::map<std::string, BaseDao*>::iterator it = this->daoMap.begin(); it != this->daoMap.end(); ++it) {
        BaseDao* dao = (BaseDao*)it->second;
        dao->clear();
    }
}
void DataBase::destroy() { CC_SAFE_DELETE(DataBase::instance); }
// add
template bool DataBase::add<BaseTable>(Dao<BaseTable>* dao);
template bool DataBase::add<TDownLoadTable>(Dao<TDownLoadTable>* dao);
template bool DataBase::add<TLayerTable>(Dao<TLayerTable>* dao);
template bool DataBase::add<TOverAllTable>(Dao<TOverAllTable>* dao);
template bool DataBase::add<TBarrierTable>(Dao<TBarrierTable>* dao);
template bool DataBase::add<TUnitTable>(Dao<TUnitTable>* dao);
template bool DataBase::add<TResourceTable>(Dao<TResourceTable>* dao);
template bool DataBase::add<TRouteTable>(Dao<TRouteTable>* dao);
template bool DataBase::add<TAssetTable>(Dao<TAssetTable>* dao);
template bool DataBase::add<MUnitTable>(Dao<MUnitTable>* dao);
template bool DataBase::add<MBarrierTable>(Dao<MBarrierTable>* dao);
template bool DataBase::add<MResourceTable>(Dao<MResourceTable>* dao);
// find
template Dao<BaseTable>* DataBase::findBy<BaseTable>();
template Dao<TDownLoadTable>* DataBase::findBy<TDownLoadTable>();
template Dao<TLayerTable>* DataBase::findBy<TLayerTable>();
template Dao<TOverAllTable>* DataBase::findBy<TOverAllTable>();
template Dao<TBarrierTable>* DataBase::findBy<TBarrierTable>();
template Dao<TUnitTable>* DataBase::findBy<TUnitTable>();
template Dao<TResourceTable>* DataBase::findBy<TResourceTable>();
template Dao<TRouteTable>* DataBase::findBy<TRouteTable>();
template Dao<TAssetTable>* DataBase::findBy<TAssetTable>();
template Dao<MUnitTable>* DataBase::findBy<MUnitTable>();
template Dao<MBarrierTable>* DataBase::findBy<MBarrierTable>();
template Dao<MResourceTable>* DataBase::findBy<MResourceTable>();

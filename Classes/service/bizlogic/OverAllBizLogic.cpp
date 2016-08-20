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
#include "DataBase.h"
#include "Dao.h"
#include "OverAllBizLogic.h"
#include "TOverAllTable.h"
OverAllBizLogic::OverAllBizLogic() {
    DataBase* db = DataBase::getInstance();
    Dao<TOverAllTable>* dao = db->findBy<TOverAllTable>();
    if (0 == dao->count()) {
        dao->save();
    }
}
TOverAllTable OverAllBizLogic::getOverAll() {
    DataBase* db = DataBase::getInstance();
    Dao<TOverAllTable>* dao = db->findBy<TOverAllTable>();
    TOverAllTable oat = dao->findFirst();
    return oat;
}
void OverAllBizLogic::saveOverAll(int currentOverAll, int toalOverAll) {
    DataBase* db = DataBase::getInstance();
    Dao<TOverAllTable>* dao = db->findBy<TOverAllTable>();
    TOverAllTable oat = dao->findFirst();
    oat.current = currentOverAll;
    oat.total = toalOverAll;
    dao->update(oat);
}
bool OverAllBizLogic::isOverAll() {
    DataBase* db = DataBase::getInstance();
    Dao<TOverAllTable>* dao = db->findBy<TOverAllTable>();
    TOverAllTable oat = dao->findFirst();
    if (oat.current == oat.total) {
        return true;
    }
    return false;
}
bool OverAllBizLogic::AddCurrentOverAll() {
    DataBase* db = DataBase::getInstance();
    Dao<TOverAllTable>* dao = db->findBy<TOverAllTable>();
    TOverAllTable oat = dao->findFirst();
    oat.current++;
    return dao->update(oat);
}
bool OverAllBizLogic::updateOverAll(int overAllLevel) {
    DataBase* db = DataBase::getInstance();
    Dao<TOverAllTable>* dao = db->findBy<TOverAllTable>();
    TOverAllTable oat = dao->findFirst();
    if (OverAllBizLogic::OVER_ALL_LEVEL1 == overAllLevel) {
        oat.reachedLevel1 = true;
    } else if (OverAllBizLogic::OVER_ALL_LEVEL2 == overAllLevel) {
        oat.reachedLevel2 = true;
    } else if (OverAllBizLogic::OVER_ALL_LEVEL3 == overAllLevel) {
        oat.reachedLevel3 = true;
    }
    return dao->update(oat);
}
float OverAllBizLogic::getCurrentPercent() {
    TOverAllTable oat = this->getOverAll();
    float percentage = (float)oat.current / (float)oat.total * 100.0f;
    return percentage;
}
void OverAllBizLogic::clear() {
    DataBase* db = DataBase::getInstance();
    Dao<TOverAllTable>* dao = db->findBy<TOverAllTable>();
    dao->clear();
}

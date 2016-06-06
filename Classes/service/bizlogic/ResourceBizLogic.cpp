//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// behaviour
#include "UnitBehaviourType.h"
#include "BehaviourCollection.h"

// service
#include "ConditionExpression.h"
#include "Dao.h"
#include "DataBase.h"
#include "FieldSchema.h"
#include "ResourceBizLogic.h"
#include "MResourceTable.h"

ResourceBizLogic::ResourceBizLogic() {}

void ResourceBizLogic::create() {
    DataBase* db = DataBase::getInstance();
    Dao<MResourceTable>* mdao = db->findBy<MResourceTable>();
    Dao<TResourceTable>* tdao = db->findBy<TResourceTable>();
    int totalGold = BehaviourCollection::getInstance()->getOrnamentCount("goldStrage");
    int totalElixir = BehaviourCollection::getInstance()->getOrnamentCount("elixirTank");
    int totalEmerald = BehaviourCollection::getInstance()->getOrnamentCount("cannon");
    totalEmerald += BehaviourCollection::getInstance()->getOrnamentCount("turret");
    totalEmerald += BehaviourCollection::getInstance()->getOrnamentCount("mortar");
    if (0 == mdao->count()) {
        MResourceTable mrt;
        mrt.emerald = totalEmerald;
        mrt.gold = totalGold;
        mrt.elixir = totalElixir;
        mdao->save(mrt);
    }

    if (0 == tdao->count()) {
        TResourceTable prt;
        prt.isEnemy = false;
        prt.gold = 0;
        prt.elixir = 0;
        prt.emerald = 0;
        prt.barbarian = 12;
        prt.archer = 12;
        prt.giant = 12;
        prt.goblin = 12;
        prt.wallbreaker = 12;
        tdao->save(prt);

        TResourceTable ert;
        ert.isEnemy = true;
        ert.gold = totalGold;
        ert.elixir = totalElixir;
        ert.emerald = totalEmerald;
        ert.barbarian = 0;
        ert.archer = 0;
        ert.giant = 0;
        ert.goblin = 0;
        ert.wallbreaker = 0;
        tdao->save(ert);
    }
}

bool ResourceBizLogic::selectUnit(int unitId) {
    DataBase* db = DataBase::getInstance();
    Dao<TResourceTable>* dao = db->findBy<TResourceTable>();
    FieldSchema<bool> field(false);
    ConditionExpression condition = ConditionExpression("isEnemy", "==", &field);
    std::vector<TResourceTable> recordVector = dao->findBy(&condition);
    if (0 == recordVector.size()) {
        return false;
    }

    TResourceTable record = recordVector[0];
    record.selectUnitType = unitId;
    dao->update(record);
    return true;
}

bool ResourceBizLogic::updateUnit(int unitId, int number) {
    DataBase* db = DataBase::getInstance();
    Dao<TResourceTable>* dao = db->findBy<TResourceTable>();
    FieldSchema<bool> field(false);
    ConditionExpression condition = ConditionExpression("isEnemy", "==", &field);
    std::vector<TResourceTable> recordVector = dao->findBy(&condition);
    if (0 == recordVector.size()) {
        return false;
    }

    TResourceTable record = recordVector[0];
    if (UnitBehaviourType::Archer == unitId) {
        record.archer -= number;
        if (0 >= record.archer) {
            record.archer = 0;
        }
    } else if (UnitBehaviourType::Barbarian == unitId) {
        record.barbarian -= number;
        if (0 >= record.barbarian) {
            record.barbarian = 0;
        }
    } else if (UnitBehaviourType::Giant == unitId) {
        record.giant -= number;
        if (0 >= record.giant) {
            record.giant = 0;
        }
    } else if (UnitBehaviourType::Goblin == unitId) {
        record.goblin -= number;
        if (0 >= record.goblin) {
            record.goblin = 0;
        }
    } else if (UnitBehaviourType::WallBreaker == unitId) {
        record.wallbreaker -= number;
        if (0 >= record.wallbreaker) {
            record.wallbreaker = 0;
        }
    }

    return dao->update(record);
}

bool ResourceBizLogic::updateGold(bool isEnemy) {
    DataBase* db = DataBase::getInstance();
    Dao<TResourceTable>* dao = db->findBy<TResourceTable>();
    FieldSchema<bool> field(isEnemy);
    ConditionExpression condition = ConditionExpression("isEnemy", "==", &field);
    std::vector<TResourceTable> recordVector = dao->findBy(&condition);
    TResourceTable record = recordVector[0];
    if (false != isEnemy) {
        record.gold--;
    } else {
        record.gold++;
    }
    return dao->update(record);
}

bool ResourceBizLogic::updateElixir(bool isEnemy) {
    DataBase* db = DataBase::getInstance();
    Dao<TResourceTable>* dao = db->findBy<TResourceTable>();
    FieldSchema<bool> field(isEnemy);
    ConditionExpression condition = ConditionExpression("isEnemy", "==", &field);
    std::vector<TResourceTable> recordVector = dao->findBy(&condition);
    TResourceTable record = recordVector[0];
    if (false != isEnemy) {
        record.elixir--;
    } else {
        record.elixir++;
    }
    return dao->update(record);
}

bool ResourceBizLogic::updateEmerald(bool isEnemy) {
    DataBase* db = DataBase::getInstance();
    Dao<TResourceTable>* dao = db->findBy<TResourceTable>();
    FieldSchema<bool> field(isEnemy);
    ConditionExpression condition = ConditionExpression("isEnemy", "==", &field);
    std::vector<TResourceTable> recordVector = dao->findBy(&condition);
    TResourceTable record = recordVector[0];
    if (false != isEnemy) {
        record.emerald--;
    } else {
        record.emerald++;
    }
    return dao->update(record);
}

int ResourceBizLogic::getEnemyResourceCount(int resourceId) {
    DataBase* db = DataBase::getInstance();

    Dao<MResourceTable>* mdao = db->findBy<MResourceTable>();
    MResourceTable master = mdao->findFirst();

    Dao<TResourceTable>* tdao = db->findBy<TResourceTable>();
    FieldSchema<bool> field(true);
    ConditionExpression condition = ConditionExpression("isEnemy", "==", &field);
    std::vector<TResourceTable> recordVector = tdao->findBy(&condition);
    TResourceTable transaction = recordVector[0];

    int ret = 0;
    if (ResourceBizLogic::RESOURCE_EMERALD == resourceId) {
        ret = transaction.emerald * ResourceBizLogic::RESOURCE_EMERALD_UNIT;
    } else if (ResourceBizLogic::RESOURCE_ELIXIR == resourceId) {
        ret = transaction.elixir * ResourceBizLogic::RESOURCE_ELIXIR_UNIT;
    } else if (ResourceBizLogic::RESOURCE_GOLD == resourceId) {
        ret = transaction.gold * ResourceBizLogic::RESOURCE_GOLD_UNIT;
    }
    return ret;
}

float ResourceBizLogic::getPlayerResourcePercent(int resourceId) {
    DataBase* db = DataBase::getInstance();

    Dao<MResourceTable>* mdao = db->findBy<MResourceTable>();
    MResourceTable master = mdao->findFirst();

    Dao<TResourceTable>* tdao = db->findBy<TResourceTable>();
    FieldSchema<bool> field(false);
    ConditionExpression condition = ConditionExpression("isEnemy", "==", &field);
    std::vector<TResourceTable> recordVector = tdao->findBy(&condition);
    TResourceTable transaction = recordVector[0];

    float rate = 0.0f;
    if (ResourceBizLogic::RESOURCE_EMERALD == resourceId) {
        rate = (float)transaction.emerald / (float)master.emerald;
    } else if (ResourceBizLogic::RESOURCE_ELIXIR == resourceId) {
        rate = (float)transaction.elixir / (float)master.elixir;
    } else if (ResourceBizLogic::RESOURCE_GOLD == resourceId) {
        rate = (float)transaction.gold / (float)master.gold;
    }
    return rate * 100.0f;
}

TResourceTable ResourceBizLogic::getPlayerResourceInfo() {
    DataBase* db = DataBase::getInstance();
    Dao<TResourceTable>* dao = db->findBy<TResourceTable>();
    FieldSchema<bool> field(false);
    ConditionExpression condition = ConditionExpression("isEnemy", "==", &field);
    std::vector<TResourceTable> recordVector = dao->findBy(&condition);
    TResourceTable transaction = recordVector[0];
    transaction.emerald *= ResourceBizLogic::RESOURCE_EMERALD_UNIT;
    transaction.elixir *= ResourceBizLogic::RESOURCE_ELIXIR_UNIT;
    transaction.gold *= ResourceBizLogic::RESOURCE_GOLD_UNIT;
    return transaction;
}

MResourceTable ResourceBizLogic::getMaxResourceInfo() {
    DataBase* db = DataBase::getInstance();
    Dao<MResourceTable>* dao = db->findBy<MResourceTable>();
    MResourceTable record = dao->findFirst();
    record.emerald *= ResourceBizLogic::RESOURCE_EMERALD_UNIT;
    record.elixir *= ResourceBizLogic::RESOURCE_ELIXIR_UNIT;
    record.gold *= ResourceBizLogic::RESOURCE_GOLD_UNIT;
    return record;
}

void ResourceBizLogic::clear() {
    DataBase* db = DataBase::getInstance();
    Dao<MResourceTable>* mdao = db->findBy<MResourceTable>();
    mdao->clear();
    Dao<TResourceTable>* tdao = db->findBy<TResourceTable>();
    tdao->clear();
}

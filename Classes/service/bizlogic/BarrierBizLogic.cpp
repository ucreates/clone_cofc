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
#include "BarrierBehaviourType.h"

// service
#include "BarrierBizLogic.h"
#include "ConditionExpression.h"
#include "DataBase.h"
#include "Dao.h"
#include "FieldSchema.h"
#include "UnitOfWork.h"

BarrierBizLogic::BarrierBizLogic() {}

TBarrierTable BarrierBizLogic::findByBarrierId(int barrierId) {
    DataBase* db = DataBase::getInstance();
    Dao<TBarrierTable>* dao = db->findBy<TBarrierTable>();
    FieldSchema<int> field(barrierId);
    ConditionExpression condition = ConditionExpression("barrierId", "==", &field);
    std::vector<TBarrierTable> recordVector = dao->findBy(&condition);
    if (0 == recordVector.size()) {
        TBarrierTable record;
        return record;
    }
    return recordVector.at(0);
}

bool BarrierBizLogic::addBarrier(int id, int type) {
    DataBase* db = DataBase::getInstance();
    Dao<TBarrierTable>* dao = db->findBy<TBarrierTable>();
    FieldSchema<int> field(id);
    ConditionExpression condition = ConditionExpression("barrierId", "==", &field);
    std::vector<TBarrierTable> recordVector = dao->findBy(&condition);
    if (0 == recordVector.size()) {
        MBarrierTable master = this->findMasterByType(type);
        TBarrierTable record;
        record.barrierId = id;
        record.type = type;
        record.hp = master.hp;
        record.power = master.power;
        return dao->save(record);
    }

    return false;
}

MBarrierTable BarrierBizLogic::findMasterByType(int type) {
    DataBase* db = DataBase::getInstance();
    Dao<MBarrierTable>* dao = db->findBy<MBarrierTable>();
    FieldSchema<int> field(type);
    ConditionExpression condition = ConditionExpression("type", "==", &field);
    std::vector<MBarrierTable> recordVector = dao->findBy(&condition);
    return recordVector[0];
}

void BarrierBizLogic::create() {
    DataBase* db = DataBase::getInstance();
    Dao<MBarrierTable>* dao = db->findBy<MBarrierTable>();
    if (0 == dao->count()) {
        this->addBarrierMaster(BarrierBehaviourType::Cannon, "cannon", 70, 5);
        this->addBarrierMaster(BarrierBehaviourType::Turret, "turrent", 120, 3);
        this->addBarrierMaster(BarrierBehaviourType::Mortar, "mortar", 150, 9);
        this->addBarrierMaster(BarrierBehaviourType::GoldStrage, "gold", 100, 0);
        this->addBarrierMaster(BarrierBehaviourType::ElixirTank, "elixir_tank", 100, 0);
        this->addBarrierMaster(BarrierBehaviourType::WoodFenceV, "wallV", 50, 0);
        this->addBarrierMaster(BarrierBehaviourType::WoodFenceH, "wallH", 50, 0);
    }
}

bool BarrierBizLogic::addBarrierMaster(int type, std::string name, int hp, int power) {
    DataBase* db = DataBase::getInstance();
    Dao<MBarrierTable>* dao = db->findBy<MBarrierTable>();
    MBarrierTable table;
    table.name = name;
    table.type = type;
    table.hp = hp;
    table.power = power;
    return dao->save(table);
}

int BarrierBizLogic::addDamage(int id, int point) {
    DataBase* db = DataBase::getInstance();
    Dao<TBarrierTable>* dao = db->findBy<TBarrierTable>();
    FieldSchema<int> field(id);
    ConditionExpression condition = ConditionExpression("barrierId", "==", &field);
    std::vector<TBarrierTable> recordVector = dao->findBy(&condition);
    if (0 == recordVector.size()) {
        return 0;
    }
    TBarrierTable record = recordVector[0];
    record.hp -= point;
    if (0 >= record.hp) {
        record.hp = 0;
    }
    if (dao->update(record)) {
        return record.hp;
    }
    return 0;
}

int BarrierBizLogic::getHp(int id) {
    DataBase* db = DataBase::getInstance();
    Dao<TBarrierTable>* dao = db->findBy<TBarrierTable>();
    FieldSchema<int> field(id);
    ConditionExpression condition = ConditionExpression("barrierId", "==", &field);
    std::vector<TBarrierTable> recordVector = dao->findBy(&condition);
    if (0 == recordVector.size()) {
        return 0;
    }
    TBarrierTable transaction = recordVector[0];
    return transaction.hp;
}

float BarrierBizLogic::getHpPercent(int id) {
    DataBase* db = DataBase::getInstance();
    Dao<TBarrierTable>* dao = db->findBy<TBarrierTable>();
    FieldSchema<int> field(id);
    ConditionExpression condition = ConditionExpression("barrierId", "==", &field);
    std::vector<TBarrierTable> recordVector = dao->findBy(&condition);
    if (0 == recordVector.size()) {
        return 0.0f;
    }

    TBarrierTable transaction = recordVector[0];
    MBarrierTable master = this->findMasterByType(transaction.type);
    float percentage = (float)transaction.hp / master.hp * 100.0f;
    return percentage;
}

bool BarrierBizLogic::destroy(int id) {
    DataBase* db = DataBase::getInstance();
    Dao<TBarrierTable>* dao = db->findBy<TBarrierTable>();
    FieldSchema<int> field(id);
    ConditionExpression condition = ConditionExpression("barrierId", "==", &field);
    std::vector<TBarrierTable> recordVector = dao->findBy(&condition);
    if (0 == recordVector.size()) {
        return false;
    }
    TBarrierTable transaction = recordVector[0];
    return dao->remove(transaction);
}

bool BarrierBizLogic::destroy(std::vector<int> destroyIdVector) {
    DataBase* db = DataBase::getInstance();
    Dao<TBarrierTable>* dao = db->findBy<TBarrierTable>();
    for (std::vector<int>::iterator it = destroyIdVector.begin(); it != destroyIdVector.end(); it++) {
        int id = *it;
        FieldSchema<int> field(id);
        ConditionExpression condition = ConditionExpression("barrierId", "==", &field);
        std::vector<TBarrierTable> recordVector = dao->findBy(&condition);
        if (0 == recordVector.size()) {
            continue;
        }

        TBarrierTable transaction = recordVector[0];
        transaction.hp = 0;
        bool ret = dao->update(transaction);
        if (false == ret) {
            return false;
        }
    }
    return true;
}

void BarrierBizLogic::clear() {
    DataBase* db = DataBase::getInstance();
    Dao<TBarrierTable>* dao = db->findBy<TBarrierTable>();
    dao->clear();
    return;
}

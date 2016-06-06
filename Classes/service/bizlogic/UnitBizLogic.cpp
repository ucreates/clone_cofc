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

// math
#include "Random.h"

// service
#include "ConditionExpression.h"
#include "Dao.h"
#include "DataBase.h"
#include "FieldSchema.h"
#include "ResourceBizLogic.h"
#include "TUnitTable.h"
#include "UnitBizLogic.h"

UnitBizLogic::UnitBizLogic() {}

void UnitBizLogic::create() {
    DataBase* db = DataBase::getInstance();
    Dao<MUnitTable>* dao = db->findBy<MUnitTable>();
    if (0 == dao->count()) {
        this->addUnitMaster(UnitBehaviourType::Archer, "archer", 60, 3);
        this->addUnitMaster(UnitBehaviourType::Barbarian, "barbarian", 100, 5);
        this->addUnitMaster(UnitBehaviourType::Giant, "giant", 150, 9);
        this->addUnitMaster(UnitBehaviourType::Goblin, "goblin", 70, 4);
        this->addUnitMaster(UnitBehaviourType::WallBreaker, "wallbreaker", 30, 1);
    }
}

TUnitTable UnitBizLogic::findByUnitId(int unitId) {
    DataBase* db = DataBase::getInstance();
    Dao<TUnitTable>* dao = db->findBy<TUnitTable>();
    FieldSchema<int> field(unitId);
    ConditionExpression cep = ConditionExpression("unitId", "==", &field);
    std::vector<TUnitTable> recordVector = dao->findBy(&cep);
    if (0 == recordVector.size()) {
        TUnitTable record;
        return record;
    }
    return recordVector.at(0);
}

bool UnitBizLogic::addUnitMaster(int type, std::string name, int hp, int power) {
    DataBase* db = DataBase::getInstance();
    Dao<MUnitTable>* dao = db->findBy<MUnitTable>();
    MUnitTable record;
    record.name = name;
    record.type = type;
    record.hp = hp;
    record.power = power;
    return dao->save(record);
}

bool UnitBizLogic::addUnit(int id, int type) {
    DataBase* db = DataBase::getInstance();
    Dao<TUnitTable>* dao = db->findBy<TUnitTable>();

    FieldSchema<int> field(id);
    ConditionExpression cep = ConditionExpression("unitId", "==", &field);
    std::vector<TUnitTable> recordVector = dao->findBy(&cep);
    if (0 == recordVector.size()) {
        int hpDiff = Random::create(10);
        int powerDiff = Random::create(2);
        MUnitTable master = this->findMasterByType(type);
        TUnitTable record;
        record.unitId = id;
        record.type = type;
        record.hp = Random::create(master.hp - hpDiff, master.hp + hpDiff);
        record.power = Random::create(master.power - powerDiff, master.power + powerDiff);
        return dao->save(record);
    }

    return false;
}

MUnitTable UnitBizLogic::findMasterByType(int type) {
    DataBase* db = DataBase::getInstance();
    Dao<MUnitTable>* dao = db->findBy<MUnitTable>();
    FieldSchema<int> field(type);
    ConditionExpression cep = ConditionExpression("type", "==", &field);
    std::vector<MUnitTable> recordVector = dao->findBy(&cep);
    return recordVector[0];
}

int UnitBizLogic::addDamage(int unitId, int point) {
    DataBase* db = DataBase::getInstance();
    Dao<TUnitTable>* dao = db->findBy<TUnitTable>();
    FieldSchema<int> field(unitId);
    ConditionExpression cep = ConditionExpression("unitId", "==", &field);
    std::vector<TUnitTable> recordVector = dao->findBy(&cep);
    if (0 == recordVector.size()) {
        return 0;
    }
    TUnitTable record = recordVector[0];
    record.hp -= point;
    if (0 >= record.hp) {
        record.hp = 0;
    }
    if (dao->update(record)) {
        return record.hp;
    }
    return 0;
}

int UnitBizLogic::getHp(int id) {
    DataBase* db = DataBase::getInstance();
    Dao<TUnitTable>* dao = db->findBy<TUnitTable>();
    FieldSchema<int> field(id);
    ConditionExpression cep = ConditionExpression("unitId", "==", &field);
    std::vector<TUnitTable> recordVector = dao->findBy(&cep);
    if (0 == recordVector.size()) {
        return 0;
    }
    TUnitTable record = recordVector[0];
    return record.hp;
}

float UnitBizLogic::getHpPercent(int id) {
    DataBase* db = DataBase::getInstance();
    Dao<TUnitTable>* dao = db->findBy<TUnitTable>();
    FieldSchema<int> field(id);
    ConditionExpression cep = ConditionExpression("unitId", "==", &field);
    std::vector<TUnitTable> recordVector = dao->findBy(&cep);
    TUnitTable transaction = recordVector[0];
    MUnitTable master = this->findMasterByType(transaction.type);
    float percentage = (float)transaction.hp / master.hp * 100.0f;
    return percentage;
}

void UnitBizLogic::clear() {
    DataBase* db = DataBase::getInstance();
    Dao<TUnitTable>* dao = db->findBy<TUnitTable>();
    dao->clear();
}
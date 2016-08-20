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
#include "AndExpression.h"
#include "ConditionExpression.h"
#include "DataBase.h"
#include "Dao.h"
#include "FieldSchema.h"
#include "RouteBizLogic.h"
#include "TRouteTable.h"
RouteBizLogic::RouteBizLogic() {}
RouteBizLogic::~RouteBizLogic() {}
std::vector<GeographicNode*> RouteBizLogic::getRouteCache(unsigned int startGeographicId, unsigned int goalGeographicId) {
    DataBase* db = DataBase::getInstance();
    Dao<TRouteTable>* dao = db->findBy<TRouteTable>();
    FieldSchema<int> field1(startGeographicId);
    FieldSchema<int> field2(goalGeographicId);
    AndExpression expression;
    expression.addCondition(ConditionExpression("startGeographicId", "==", &field1));
    expression.addCondition(ConditionExpression("goalGeographicId", "==", &field2));
    std::vector<TRouteTable> recordVector = dao->findBy(&expression);
    std::vector<GeographicNode*> ret;
    if (0 == recordVector.size()) {
        return ret;
    }
    TRouteTable record = recordVector.at(0);
    ret = record.routeCacheVector;
    return ret;
}
bool RouteBizLogic::addRouteCache(unsigned int startGeographicId, unsigned int goalGeographicId, std::vector<GeographicNode*> routeVector) {
    DataBase* db = DataBase::getInstance();
    Dao<TRouteTable>* dao = db->findBy<TRouteTable>();
    TRouteTable record;
    record.startGeographicId = startGeographicId;
    record.goalGeographicId = goalGeographicId;
    record.routeCacheVector = routeVector;
    return dao->save(record);
}
bool RouteBizLogic::removeRouteCache(unsigned int startGeographicId, unsigned int goalGeographicId) {
    DataBase* db = DataBase::getInstance();
    Dao<TRouteTable>* dao = db->findBy<TRouteTable>();
    FieldSchema<int> field1(startGeographicId);
    FieldSchema<int> field2(goalGeographicId);
    AndExpression expression;
    expression.addCondition(ConditionExpression("startGeographicId", "==", &field1));
    expression.addCondition(ConditionExpression("goalGeographicId", "==", &field2));
    std::vector<TRouteTable> recordVector = dao->findBy(&expression);
    if (0 == recordVector.size()) {
        return false;
    }
    TRouteTable record = recordVector.at(0);
    return dao->remove(record);
}
void RouteBizLogic::clear() {
    DataBase* db = DataBase::getInstance();
    Dao<TRouteTable>* dao = db->findBy<TRouteTable>();
    dao->clear();
    return;
}

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
#include "LayerBizLogic.h"
#include "TLayerTable.h"
using namespace cocos2d;
LayerBizLogic::LayerBizLogic() {}
int LayerBizLogic::getLayerId() {
    DataBase* db = DataBase::getInstance();
    Dao<TLayerTable>* dao = db->findBy<TLayerTable>();
    if (0 == dao->count()) {
        return -1;
    }
    TLayerTable table = dao->findBy(1);
    return table.layerId;
}
void LayerBizLogic::setLayerId(int layerId) {
    DataBase* db = DataBase::getInstance();
    Dao<TLayerTable>* dao = db->findBy<TLayerTable>();
    TLayerTable table;
    if (0 == dao->count()) {
        table.layerId = layerId;
        dao->save(table);
    } else {
        table = dao->findBy(1);
        table.layerId = layerId;
        dao->update(table);
    }
}
Layer* LayerBizLogic::getLayer() {
    DataBase* db = DataBase::getInstance();
    Dao<TLayerTable>* dao = db->findBy<TLayerTable>();
    if (0 == dao->count()) {
        return NULL;
    }
    TLayerTable table = dao->findBy(1);
    return table.layer;
}
Layer* LayerBizLogic::getLayer(int layerId) {
    DataBase* db = DataBase::getInstance();
    Dao<TLayerTable>* dao = db->findBy<TLayerTable>();
    if (0 == dao->count()) {
        return NULL;
    }
    TLayerTable table;
    std::vector<TLayerTable> recordVector = dao->findAll();
    std::vector<TLayerTable>::iterator it = recordVector.begin();
    while (it != recordVector.end()) {
        table = (*it);
        if (table.layerId == layerId) {
            return table.layer;
        }
        ++it;
    }
    return NULL;
}
void LayerBizLogic::setLayer(Layer* layer) {
    DataBase* db = DataBase::getInstance();
    Dao<TLayerTable>* dao = db->findBy<TLayerTable>();
    TLayerTable table;
    if (0 == dao->count()) {
        table.layer = layer;
        dao->save(table);
    } else {
        table = dao->findBy(1);
        table.layer = layer;
        dao->update(table);
    }
}
void LayerBizLogic::setLayer(int layerId, Layer* layer) {
    DataBase* db = DataBase::getInstance();
    Dao<TLayerTable>* dao = db->findBy<TLayerTable>();
    TLayerTable table;
    Layer* savedlayer = this->getLayer(layerId);
    if (NULL == savedlayer) {
        table.layerId = layerId;
        table.layer = layer;
        dao->save(table);
    } else {
        table.layer = layer;
        dao->update(table);
    }
}

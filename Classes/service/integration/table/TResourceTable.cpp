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
#include "TResourceTable.h"
#include "FieldSchema.h"

TResourceTable::TResourceTable() {
    this->isEnemy = false;
    this->gold = 0;
    this->elixir = 0;
    this->archer = 0;
    this->barbarian = 0;
    this->giant = 0;
    this->goblin = 0;
    this->wallbreaker = 0;
    this->emerald = 0;
    this->selectUnitType = 0;
}

void TResourceTable::build() {
    this->primaryKey.set("id", this->id);
    this->compareFieldIterator.set("isEnemy", new FieldSchema<bool>(this->isEnemy));
    this->compareFieldIterator.set("gold", new FieldSchema<int>(this->gold));
    this->compareFieldIterator.set("elixir", new FieldSchema<int>(this->elixir));
    this->compareFieldIterator.set("emerald", new FieldSchema<int>(this->emerald));
    this->compareFieldIterator.set("archer", new FieldSchema<int>(this->archer));
    this->compareFieldIterator.set("barbarian", new FieldSchema<int>(this->barbarian));
    this->compareFieldIterator.set("giant", new FieldSchema<int>(this->giant));
    this->compareFieldIterator.set("goblin", new FieldSchema<int>(this->goblin));
    this->compareFieldIterator.set("wallbreaker", new FieldSchema<int>(this->wallbreaker));
    this->compareFieldIterator.set("selectUnitType", new FieldSchema<int>(this->selectUnitType));
}

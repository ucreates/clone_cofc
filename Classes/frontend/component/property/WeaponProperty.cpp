//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "WeaponProperty.h"

WeaponProperty::WeaponProperty(std::string name, int id, int ownerId, bool isEnemy) {
    this->name = name;
    this->id = id;
    this->ownerId = ownerId;
    this->type = "weapon";
    this->isEnemyWeapon = isEnemy;
}

WeaponProperty::~WeaponProperty() {}

bool WeaponProperty::isEnemy() { return this->isEnemyWeapon; }

int WeaponProperty::getOwnerId() { return this->ownerId; }

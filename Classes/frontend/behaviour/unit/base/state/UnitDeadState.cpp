//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "UnitDeadState.h"
#include "ArcherBehaviour.h"
#include "BarbarianBehaviour.h"
#include "GiantBehaviour.h"
#include "GoblinBehaviour.h"
#include "WallBreakerBehaviour.h"
#include "GraveBehaviour.h"
#include "BehaviourMapper.h"
#include "DeadEffectBehaviour.h"

template <typename T>
UnitDeadState<T>::UnitDeadState() {}

template <typename T>
UnitDeadState<T>::~UnitDeadState() {}

template <typename T>
void UnitDeadState<T>::dead(T* owner) {
    AnimatorAsset* asset = (AnimatorAsset*)owner->getAsset("anime");
    asset->hide();

    Transform transform = asset->getTransform();
    Position pos = transform.getPosition();
    GeographicNode* node = owner->getGeographicNode();
    BehaviourMapper* mapper = BehaviourMapper::getInstance();
    mapper->addMappingList(new GraveBehaviour(node), pos);
    owner->getProperty()->setStatus(BehaviourStatus::COMPLETE);
}

template class UnitDeadState<ArcherBehaviour>;
template class UnitDeadState<BarbarianBehaviour>;
template class UnitDeadState<GiantBehaviour>;
template class UnitDeadState<GoblinBehaviour>;
template class UnitDeadState<WallBreakerBehaviour>;
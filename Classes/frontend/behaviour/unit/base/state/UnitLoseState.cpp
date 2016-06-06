//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "cocos2d.h"

#include "ArcherBehaviour.h"
#include "BarbarianBehaviour.h"
#include "GiantBehaviour.h"
#include "GoblinBehaviour.h"
#include "WallBreakerBehaviour.h"
#include "TowerArcherBehaviour.h"

#include "UnitLoseState.h"

// geography
#include "GeographicNode.h"

// animator
#include "AnimatorAsset.h"

// utility
#include "Degree.h"
#include "Direction.h"

// math
#include "Random.h"

using namespace cocos2d;

template <typename T>
UnitLoseState<T>::UnitLoseState() {}

template <typename T>
UnitLoseState<T>::~UnitLoseState() {}

template <typename T>
void UnitLoseState<T>::changeDirection(T* owner) {
    AnimatorAsset* asset = (AnimatorAsset*)owner->getAsset("anime");
    Transform entity = asset->getTransform();
    Vec2 position = entity.getPosition().vector2d;
    GeographicNode* node = owner->getGeographicNode();
    float degree = Degree::create(position, node->position);

    Direction::DIRECT direction = Direction::getDirection(degree);
    if (direction == Direction::DIRECT::HORIZON_RIGHT) {
        asset->play("side_lose");
        asset->transform(false);
    } else if (direction == Direction::DIRECT::HORIZON_LEFT) {
        asset->play("side_lose");
        asset->transform(true);
    } else if (direction == Direction::DIRECT::UPPER_RIGHT) {
        asset->play("upper_lose");
        asset->transform(false);
    } else if (direction == Direction::DIRECT::UPPER_LEFT) {
        asset->play("upper_lose");
        asset->transform(true);
    } else if (direction == Direction::DIRECT::UNDER_RIGHT) {
        asset->play("under_lose");
        asset->transform(false);
    } else if (direction == Direction::DIRECT::UNDER_LEFT) {
        asset->play("under_lose");
        asset->transform(true);
    }
    return;
}

template class UnitLoseState<ArcherBehaviour>;
template class UnitLoseState<BarbarianBehaviour>;
template class UnitLoseState<GiantBehaviour>;
template class UnitLoseState<GoblinBehaviour>;
template class UnitLoseState<WallBreakerBehaviour>;
template class UnitLoseState<TowerArcherBehaviour>;
//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "BarrierDestroyState.h"
#include "CannonBehaviour.h"
#include "TurretBehaviour.h"
#include "WoodFenceVBehaviour.h"
#include "WoodFenceHBehaviour.h"
#include "MortarBehaviour.h"
#include "GoldStrageBehaviour.h"
#include "ElixirTankBehaviour.h"
#include "Notifier.h"
#include "NotifyMessage.h"

template <typename T>
BarrierDestroyState<T>::BarrierDestroyState() {}

template <typename T>
BarrierDestroyState<T>::~BarrierDestroyState() {}

template <typename T>
void BarrierDestroyState<T>::notifyOverAll(TOverAllTable overAll) {
    if (false == overAll.reachedLevel1) {
        Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_OverAll_Level1_State);
    } else if (false == overAll.reachedLevel2) {
        Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_OverAll_Level2_State);
    } else if (false == overAll.reachedLevel3) {
        Notifier::getInstance()->notify(NotifyMessage::Battle_Scene_OverAll_Level3_State);
    }
}

template class BarrierDestroyState<CannonBehaviour>;
template class BarrierDestroyState<TurretBehaviour>;
template class BarrierDestroyState<WoodFenceVBehaviour>;
template class BarrierDestroyState<WoodFenceHBehaviour>;
template class BarrierDestroyState<MortarBehaviour>;
template class BarrierDestroyState<GoldStrageBehaviour>;
template class BarrierDestroyState<ElixirTankBehaviour>;
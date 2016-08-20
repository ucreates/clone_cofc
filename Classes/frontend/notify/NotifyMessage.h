//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef NotifyMessage_h
#define NotifyMessage_h
enum NotifyMessage {
    Logo_Scene_Show_State = 0x0000,
    Logo_Scene_Complete_State = 0x0001,
    Loading_Scene_Show_State = 0x0002,
    Loading_Scene_Complete_State = 0x0003,
    Battle_Scene_Build_State = 0x0004,
    Battle_Scene_Win_State = 0x0005,
    Battle_Scene_Lose_State = 0x0006,
    Battle_Scene_Battle_State = 0x0007,
    Battle_Scene_Observation_State = 0x0008,
    Battle_Scene_Shake_State = 0x0009,
    Battle_Scene_Score_Update_State = 0x000A,
    Battle_Scene_OverAll_Level1_State = 0x000B,
    Battle_Scene_OverAll_Level2_State = 0x000C,
    Battle_Scene_OverAll_Level3_State = 0x000D,
    Battle_Scene_Complete_State = 0x000E,
    Battle_Scene_Battle_Attack_State = 0x000F,
    Behaviour_Unit_Move = 0x0010,
    Behaviour_Unit_Attack = 0x0011,
    Behaviour_Unit_Damage = 0x0012,
    Behaviour_Unit_Dead = 0x0013,
    Behaviour_Unit_Life_Show = 0x0014,
    Behaviour_Unit_Beacon_Show = 0x0015,
    Behaviour_Barrier_Destroy = 0x0016,
    Behaviour_Barrier_Cannon_Search = 0x0017,
    Behaviour_Barrier_Cannon_Attack = 0x0018,
    Behaviour_Barrier_ElixirTank_Damage = 0x0019,
    Behaviour_Barrier_Mortar_Damage = 0x001A,
    Behaviour_Barrier_Mortar_Atack = 0x001B,
    Behaviour_Barrier_Mortar_Pause = 0x001C,
    Behaviour_Barrier_Tower_Archer_Search = 0x001D,
    Behaviour_Barrier_Tower_Archer_Attack = 0x001E,
    Behaviour_Barrier_Touch_Began = 0x001F,
    Behaviour_Barrier_Touch_End = 0x0020,
    Behaviour_Barrier_Damage = 0x0021,
    Behaviour_Barrier_Life_Show = 0x0022,
    Behaviour_Weapon_Active = 0x0023,
    Behaviour_Weapon_Destroy = 0x0024,
    Route_Search_Test_Viewer_Route = 0xF001,
    Route_Search_Test_Viewer_Normal = 0xF002,
    Route_Search_Test_Viewer_Start = 0xF003,
    Route_Search_Test_Viewer_Goal = 0xF004,
    Route_Search_Test_Viewer_Node = 0xF005,
    Geography_Editor_Reset = 0xF006,
};
#endif

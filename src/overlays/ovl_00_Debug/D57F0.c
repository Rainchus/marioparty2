#include "common.h"

extern PlayerData debug_gPlayers[4];
extern s32 D_800F8420_F9020;
extern f32 D_800FA610_FB210;
extern Vec D_800FD474_FE074;
extern Vec D_8010274C_10334C;
extern char D_80101080_101C80[];
extern char D_8010720C_DA1FC_Debug[];
extern char D_80107220_DA210_Debug[];
extern char D_80107228_DA218_Debug[];
extern u8 D_80107470_DA460_Debug[];
extern u16 D_80107406_DA3F6_Debug;
void DrawDebugText(u16, u16, char*);
s32 func_800172CC_17ECC(s16);
void func_8001A614_1B214(u16);
void func_8001CA48_1D648(void);
void func_80067D90_68990(void);
void func_80068964_69564(void);
void func_800689A0_695A0(void);
void func_80068A20_69620(void);
void func_80103838_D6828_Debug(omObjData*);
void func_80105B5C_D8B4C_Debug(u16, u16, char*, u16, u16);
void func_80105BDC_D8BCC_Debug(void);
void func_80104FB4_D7FA4_Debug(omObjData* obj);

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80102800_D57F0_Debug);

void func_80102D54_D5D44_Debug(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    func_80018E30_19A30(1);
    D_800FA610_FB210 = arg0;
    D_800FD474_FE074.x = arg1;
    D_800FD474_FE074.y = arg2;
    D_800FD474_FE074.z = arg3;
    D_8010274C_10334C.x = arg4;
    D_8010274C_10334C.y = arg5;
    D_8010274C_10334C.z = arg6;
}

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80102DEC_D5DDC_Debug);

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80103594_D6584_Debug);

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80103838_D6828_Debug);

void func_80103C4C_D6C3C_Debug(omObjData* arg0) {
    s32 i;

    rand8();
    sprintf(D_80101080_101C80, D_8010720C_DA1FC_Debug);
    func_80105B5C_D8B4C_Debug(0x60, 0x58, D_80101080_101C80, 0xE, 6);
    sprintf(D_80101080_101C80, D_80107220_DA210_Debug);
    func_80105B5C_D8B4C_Debug(0x70, 0x68, D_80101080_101C80, 0xD, 5);
    sprintf(D_80101080_101C80, D_80107228_DA218_Debug);
    func_80105B5C_D8B4C_Debug(0x70, 0x70, D_80101080_101C80, 0xD, 5);
    for (i = 0; i < MAX_PLAYERS; i++) {
        if (func_800172CC_17ECC(i) == 0) {
            continue;
        }
        
        if (D_80107470_DA460_Debug[i] & 0x20) {
            func_8001A614_1B214(D_80107406_DA3F6_Debug);
            arg0->func_ptr = &func_80103838_D6828_Debug;
            continue;
        }
        
        if (D_80107470_DA460_Debug[i] & 0x10) {
            func_80067D90_68990();
            func_800689A0_695A0();
            func_8001A614_1B214(D_80107406_DA3F6_Debug);
            func_8001CA48_1D648();
            func_80068964_69564();
            func_80068A20_69620();
            for (i = 0; i < MAX_PLAYERS; i++) {
                debug_gPlayers[i] = gPlayers[i];
            }
            func_80105BDC_D8BCC_Debug();
            arg0->func_ptr = &func_80103838_D6828_Debug;
        }
    }
}

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80103E50_D6E40_Debug);

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80104ADC_D7ACC_Debug);

void func_80104FA4_D7F94_Debug(omObjData* obj) {
    obj->func_ptr = func_80104FB4_D7FA4_Debug;
}

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80104FB4_D7FA4_Debug);

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80105964_D8954_Debug);

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_801059B0_D89A0_Debug);

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80105A2C_D8A1C_Debug);

void func_80105B5C_D8B4C_Debug(u16 arg0, u16 arg1, char* arg2, u16 arg3, u16 arg4) {
    D_800F8420_F9020 = arg4;
    DrawDebugText((arg0 + 1), (arg1 + 1), arg2);
    D_800F8420_F9020 = arg3;
    DrawDebugText(arg0, arg1, arg2);
}

#ifdef NON_MATCHING
//matches but symbols are off
extern u8 D_80106490_D9480[4][16];
extern s16 D_801072A0_DA290;
extern s16 D_801072A2_DA292;

void func_80105BDC_D8BCC_Debug(void) {
    PlayerData* temp_v0;
    u8* temp_v1;

    temp_v1 = &D_80106490_D9480[debug_ovl_table[D_801072A0_DA290 * 10 + D_801072A2_DA292].overlayID];
    temp_v0 = debug_gPlayers;
    (temp_v0++)->group = temp_v1[0];
    (temp_v0++)->group = temp_v1[1];
    (temp_v0++)->group = temp_v1[2];
    (temp_v0++)->group = temp_v1[3];
}
#else
INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80105BDC_D8BCC_Debug);
#endif

void func_80105C50_D8C40_Debug(void) {
    s32 i;
    PlayerData* player;
    PlayerData* debugPlayer;

    for (i = 0; i < MAX_PLAYERS; i++, player++, debugPlayer++) {
        debugPlayer = &debug_gPlayers[i];
        player = &gPlayers[i];
        
        player->flags = debugPlayer->flags;
        player->group = debugPlayer->group;
        player->controller_port = debugPlayer->controller_port;
        player->cpu_difficulty = debugPlayer->cpu_difficulty;
        player->coins = debugPlayer->coins;
    }
}

void func_80105CC0_D8CB0_Debug(void) {
    u8 playerGroups[MAX_PLAYERS];
    u8 sp18[MAX_PLAYERS];
    s32 i;
    s32 randInt;

    for (i = 0; i < MAX_PLAYERS; i++) {
        playerGroups[i] = debug_gPlayers[i].group;
        sp18[i] = 0;
    }

    for (i = 0; i < MAX_PLAYERS; i++) {
        while (1) {
            randInt = rand8() & 3;
            if (sp18[randInt] != 1) {
                break;
            }
        }
        sp18[randInt] = 1;
        debug_gPlayers[i].group = playerGroups[randInt];
    }
}

void func_80105D9C_D8D8C_Debug(void) {
    u8 sp10[MAX_PLAYERS];
    s32 i;
    s32 randInt;

    for (i = 0; i < MAX_PLAYERS; i++) {
        sp10[i] = 0;
    }

    for (i = 0; i < MAX_PLAYERS; i++) {
        while (1) {
            randInt = rand8() & 3;
            if (sp10[randInt] != 1) {
                break;
            }
        }
        sp10[randInt] = 1;
        debug_gPlayers[i].controller_port = randInt;
    }
}
